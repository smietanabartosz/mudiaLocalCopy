/*
 * Copyright  Onplick <info@onplick.com> - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */
#include "board.h"
#include "usb_device_config.h"
#include "usb.h"
#include "usb_device.h"
#include "usb_device_class.h"
#include "usb_device_descriptor.h"
#include "composite.h"
#include "usb_phy.h"
#include "log.hpp"

#ifndef UNUSED
#define UNUSED(x) do { (void)(x); } while (0)
#endif

#if (defined(USB_DEVICE_CONFIG_CHARGER_DETECT) && (USB_DEVICE_CONFIG_CHARGER_DETECT > 0U)) &&                          \
    (defined(FSL_FEATURE_SOC_USB_ANALOG_COUNT) && (FSL_FEATURE_SOC_USB_ANALOG_COUNT > 0U))
#include "usb_charger_detect.h"
#endif

extern usb_device_class_struct_t g_UsbDeviceCdcVcomConfig;
#if defined(USB_DEVICE_CONFIG_MTP) && (USB_DEVICE_CONFIG_MTP > 0U)
extern usb_device_class_struct_t g_MtpClass;
#endif

/* Composite device structure. */
static usb_device_composite_struct_t composite;
static usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param);

/* USB device class information */
static usb_device_class_config_struct_t g_CompositeClassConfig[] = {
#if defined(USB_DEVICE_CONFIG_MTP) && (USB_DEVICE_CONFIG_MTP > 0U)
    {
        MtpUSBCallback,
        &composite.mtpApp,
        (class_handle_t)NULL,
        &g_MtpClass,
    },
#endif
    {
        VirtualComUSBCallback,
        &composite.cdcVcom,
        (class_handle_t)NULL,
        &g_UsbDeviceCdcVcomConfig,
    }};

#if defined(USB_DEVICE_CONFIG_MTP) && (USB_DEVICE_CONFIG_MTP > 0U)
static class_handle_t g_MtpClassHandle = (class_handle_t)NULL;
#endif
static class_handle_t g_VComClassHandle = (class_handle_t)NULL;

#if (defined(USB_DEVICE_CONFIG_CHARGER_DETECT) && (USB_DEVICE_CONFIG_CHARGER_DETECT > 0U)) &&                          \
    (defined(FSL_FEATURE_SOC_USB_ANALOG_COUNT) && (FSL_FEATURE_SOC_USB_ANALOG_COUNT > 0U))
void USB_UpdateHwTick(void)
{
    USB_DeviceUpdateHwTick(composite.deviceHandle, xTaskGetTickCount());
}
#endif

/* USB device class configuration information */
static usb_device_class_config_list_struct_t g_UsbDeviceCompositeConfigList = {
    g_CompositeClassConfig,
    USB_DeviceCallback,
    sizeof(g_CompositeClassConfig) / sizeof(usb_device_class_config_struct_t),
};

void USB_OTG1_IRQHandler(void)
{
    USB_DeviceEhciIsrFunction(composite.deviceHandle);
    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
    exception return operation might vector to incorrect interrupt */
    __DSB();
}

void USB_OTG2_IRQHandler(void)
{
    USB_DeviceEhciIsrFunction(composite.deviceHandle);
    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
    exception return operation might vector to incorrect interrupt */
    __DSB();
}

static uint32_t USB_DeviceClockInit(void)
{
    usb_phy_config_struct_t phyConfig = {
        BOARD_USB_PHY_D_CAL,
        BOARD_USB_PHY_TXCAL45DP,
        BOARD_USB_PHY_TXCAL45DM,
    };

    if (CONTROLLER_ID == kUSB_ControllerEhci0) {
        CLOCK_EnableUsbhs0PhyPllClock(kCLOCK_Usbphy480M, 480000000U);
        CLOCK_EnableUsbhs0Clock(kCLOCK_Usb480M, 480000000U);
    }
    else {
        CLOCK_EnableUsbhs1PhyPllClock(kCLOCK_Usbphy480M, 480000000U);
        CLOCK_EnableUsbhs1Clock(kCLOCK_Usb480M, 480000000U);
    }
    return USB_EhciPhyInit(CONTROLLER_ID, BOARD_XTAL0_CLK_HZ, &phyConfig);
}

static void USB_DeviceClockDeinit(void)
{
    USB_EhciPhyDeinit(CONTROLLER_ID);

    if (CONTROLLER_ID == kUSB_ControllerEhci0) {
        CLOCK_DisableUsbhs0PhyPllClock();
    }
    else {
        CLOCK_DisableUsbhs1PhyPllClock();
    }
}

static void USB_DevicePllInit(void)
{
    if (CONTROLLER_ID == kUSB_ControllerEhci0) {
        // Power on USB1 PLL
        CCM_ANALOG->PLL_USB1_CLR = CCM_ANALOG_PLL_USB1_BYPASS_MASK;
        CCM_ANALOG->PLL_USB1_SET = CCM_ANALOG_PLL_USB1_POWER_MASK;
    }
    else {
        // Power on USB2 PLL
        CCM_ANALOG->PLL_USB2_CLR = CCM_ANALOG_PLL_USB2_BYPASS_MASK;
        CCM_ANALOG->PLL_USB2_SET = CCM_ANALOG_PLL_USB2_POWER_MASK;
    }
}

static void USB_DevicePllDeinit(void)
{
    if (CONTROLLER_ID == kUSB_ControllerEhci0) {
        // Power off USB1 PLL
        CCM_ANALOG->PLL_USB1_SET = CCM_ANALOG_PLL_USB1_BYPASS_MASK;
        CCM_ANALOG->PLL_USB1_CLR = CCM_ANALOG_PLL_USB1_POWER_MASK;
    }
    else {
        // Power off USB2 PLL
        CCM_ANALOG->PLL_USB2_SET = CCM_ANALOG_PLL_USB2_BYPASS_MASK;
        CCM_ANALOG->PLL_USB2_CLR = CCM_ANALOG_PLL_USB2_POWER_MASK;
    }
}

static void USB_DevicePhyDeinit(void)
{
    if (CONTROLLER_ID == kUSB_ControllerEhci0) {
        USBPHY1->PWD = 0xFFFFFFFF;
    }
    else {
        USBPHY2->PWD = 0xFFFFFFFF;
    }
}

static void USB_DeviceSetIsr(bool enable)
{
    uint8_t irqNumber;

    uint8_t usbDeviceEhciIrq[] = USBHS_IRQS;
    irqNumber                  = usbDeviceEhciIrq[CONTROLLER_ID - kUSB_ControllerEhci0];

    if (enable) {
        /* Install isr, set priority, and enable IRQ. */
        NVIC_SetPriority((IRQn_Type)irqNumber, USB_DEVICE_INTERRUPT_PRIORITY);
        EnableIRQ((IRQn_Type)irqNumber);
    }
    else {
        DisableIRQ((IRQn_Type)irqNumber);
    }
}

#if defined(USB_DEVICE_CONFIG_USE_TASK) && (USB_DEVICE_CONFIG_USE_TASK > 0U)
void USB_DeviceTaskFn(void *deviceHandle)
{
    USB_DeviceEhciTaskFunction(deviceHandle);
}
#endif

#if defined(USB_DEVICE_CONFIG_USE_TASK) && (USB_DEVICE_CONFIG_USE_TASK > 0U)
void USB_DeviceTask(void *handle)
{
    while (1U) {
        USB_DeviceTaskFn(handle);
    }
}
#endif

#if (defined(USB_DEVICE_CONFIG_CHARGER_DETECT) && (USB_DEVICE_CONFIG_CHARGER_DETECT > 0U)) &&                          \
    (defined(FSL_FEATURE_SOC_USB_ANALOG_COUNT) && (FSL_FEATURE_SOC_USB_ANALOG_COUNT > 0U))

extern void USB_ChargerDetectedCB(uint8_t detectionState);

/// Check BC1.2 standard and IMX RT1051 Reference Manual(43.4.7 Charger detection) for more info
static void charger_detected_callback(const usb_device_charger_detect_type_t type)
{
    USB_ChargerDetectedCB(type);

    /// Enable USB enumeration only for Standard Downstream port and Charging Downstream port
    if (type == kUSB_DcdCDP || type == kUSB_DcdSDP) {
        USB_DeviceRun(composite.deviceHandle);
    }
}
#endif

static usb_status_t USB_DeviceCallback(usb_device_handle handle, uint32_t event, void *param)
{
    usb_status_t error = kStatus_USB_Error;
    uint16_t *temp16   = (uint16_t *)param;
    uint8_t *temp8     = (uint8_t *)param;

    switch (event) {
    case kUSB_DeviceEventBusReset: {
        composite.attach               = 0;
        composite.currentConfiguration = 0U;
        error                          = kStatus_USB_Success;
#if (defined(USB_DEVICE_CONFIG_EHCI) && (USB_DEVICE_CONFIG_EHCI > 0U))
        /* Get USB speed to configure the device, including max packet size and interval of the endpoints. */
        if (kStatus_USB_Success == USB_DeviceClassGetSpeed(CONTROLLER_ID, &composite.speed)) {
            USB_DeviceSetSpeed(handle, composite.speed);
        }
#endif
        VirtualComReset(&composite.cdcVcom, composite.speed);

#if defined(USB_DEVICE_CONFIG_MTP) && (USB_DEVICE_CONFIG_MTP > 0U)
        MtpReset(&composite.mtpApp, composite.speed);
#endif
        composite.userDefinedEventCallback(composite.userDefinedEventCallbackArg, USB_EVENT_RESET);
    } break;
    case kUSB_DeviceEventSetConfiguration:
        if (0U == (*temp8)) {
            composite.attach               = 0;
            composite.currentConfiguration = 0U;
        }
        else if (USB_COMPOSITE_CONFIGURE_INDEX == (*temp8)) {
            composite.attach               = 1;
            composite.currentConfiguration = *temp8;
            VirtualComUSBSetConfiguration(&composite.cdcVcom, *temp8);
            error = kStatus_USB_Success;
        }
        else {
            error = kStatus_USB_InvalidRequest;
        }
        break;
    case kUSB_DeviceEventSetInterface:
        if (composite.attach) {
            uint8_t interface        = (uint8_t)((*temp16 & 0xFF00U) >> 0x08U);
            uint8_t alternateSetting = (uint8_t)(*temp16 & 0x00FFU);
            if (interface < USB_INTERFACE_COUNT) {
                composite.currentInterfaceAlternateSetting[interface] = alternateSetting;
                error                                                 = kStatus_USB_Success;
            }
        }
        break;
    case kUSB_DeviceEventGetConfiguration:
        if (param) {
            *temp8 = composite.currentConfiguration;
            error  = kStatus_USB_Success;
        }
        break;
    case kUSB_DeviceEventGetInterface:
        if (param) {
            uint8_t interface = (uint8_t)((*temp16 & 0xFF00U) >> 0x08U);
            if (interface < USB_INTERFACE_COUNT) {
                *temp16 = (*temp16 & 0xFF00U) | composite.currentInterfaceAlternateSetting[interface];
                error   = kStatus_USB_Success;
            }
            else {
                error = kStatus_USB_InvalidRequest;
            }
        }
        break;
    case kUSB_DeviceEventGetDeviceDescriptor:
        if (param) {
            error = USB_DeviceGetDeviceDescriptor(handle, (usb_device_get_device_descriptor_struct_t *)param);
        }
        break;
    case kUSB_DeviceEventGetConfigurationDescriptor:
        if (param) {
            error =
                USB_DeviceGetConfigurationDescriptor(handle, (usb_device_get_configuration_descriptor_struct_t *)param);
        }
        break;
    case kUSB_DeviceEventGetStringDescriptor:
        if (param) {
            error = USB_DeviceGetStringDescriptor(handle, (usb_device_get_string_descriptor_struct_t *)param);
        }
        break;
#if (defined(USB_DEVICE_CONFIG_CV_TEST) && (USB_DEVICE_CONFIG_CV_TEST > 0U))
    case kUSB_DeviceEventGetDeviceQualifierDescriptor:
        if (param) {
            error = USB_DeviceGetDeviceQualifierDescriptor(
                handle, (usb_device_get_device_qualifier_descriptor_struct_t *)param);
        }
        break;
#endif

    case kUSB_DeviceEventAttach:
        VirtualComAttached(&composite.cdcVcom);
        composite.userDefinedEventCallback(composite.userDefinedEventCallbackArg, USB_EVENT_ATTACHED);
        break;

    case kUSB_DeviceEventDetach:
        VirtualComDetached(&composite.cdcVcom);
#if defined(USB_DEVICE_CONFIG_MTP) && (USB_DEVICE_CONFIG_MTP > 0U)
        MtpDetached(&composite.mtpApp);
#endif
        composite.userDefinedEventCallback(composite.userDefinedEventCallbackArg, USB_EVENT_DETACHED);
        break;
#if (defined(USB_DEVICE_CONFIG_CHARGER_DETECT) && (USB_DEVICE_CONFIG_CHARGER_DETECT > 0U)) &&                          \
    (defined(FSL_FEATURE_SOC_USB_ANALOG_COUNT) && (FSL_FEATURE_SOC_USB_ANALOG_COUNT > 0U))
    case kUSB_DeviceEventDcdDetectionfinished:
        charger_detected_callback(*(const usb_device_charger_detect_type_t *)param);
        composite.userDefinedEventCallback(composite.userDefinedEventCallbackArg, USB_EVENT_DCD_FINISHED);
        break;
#endif

    default:
        break;
    }

    return error;
}

usb_device_composite_struct_t *composite_init(usb_event_callback_t userEventCallback,
                                              const char *serialNumber,
                                              const uint16_t bcdDeviceVersion,
                                              const char *mtpRoot,
                                              bool mtpLockedAtInit)
{
    if (USB_DeviceClockInit() != kStatus_USB_Success) {
        log_error("[Composite] USB Device Clock init failed");
    }

    composite.speed                       = USB_SPEED_FULL;
    composite.attach                      = 0;
    composite.cdcVcom.cdcAcmHandle        = (class_handle_t)NULL;
    composite.deviceHandle                = NULL;
    composite.userDefinedEventCallback    = userEventCallback;
    composite.userDefinedEventCallbackArg = NULL; // not used

    if ((serialNumber != NULL) && (serialNumber[0] != '\0')) {
        USB_DeviceSetSerialNumberString(serialNumber);
    }

    USB_DeviceSetBcdVersion(&composite.deviceHandle, bcdDeviceVersion);

    USB_DevicePllInit();

    log_debug("VBUS_DETECT: 0x%08x\r\n", (unsigned int)USB_ANALOG->INSTANCE[0].VBUS_DETECT);
    log_debug("VBUS_DETECT_STAT: 0x%08x\r\n", (unsigned int)USB_ANALOG->INSTANCE[0].VBUS_DETECT_STAT);

    if (kStatus_USB_Success !=
        USB_DeviceClassInit(CONTROLLER_ID, &g_UsbDeviceCompositeConfigList, &composite.deviceHandle)) {
        log_error("[Composite] USB Device init failed");
        goto error;
    }
    else {
#if defined(USB_DEVICE_CONFIG_MTP) && (USB_DEVICE_CONFIG_MTP > 0U)
        g_MtpClassHandle  = g_CompositeClassConfig[0].classHandle;
        g_VComClassHandle = g_CompositeClassConfig[1].classHandle;

        if (MtpInit(&composite.mtpApp, g_MtpClassHandle, mtpRoot, mtpLockedAtInit) != kStatus_USB_Success) {
            log_error("[Composite] MTP initialization failed");
            goto error;
        }
#else
        UNUSED(mtpRoot);
        UNUSED(mtpLockedAtInit);
        g_VComClassHandle = g_CompositeClassConfig[0].classHandle;
#endif
        if (VirtualComInit(
                &composite.cdcVcom, g_VComClassHandle, composite.userDefinedEventCallback, (void *)serialNumber) !=
            kStatus_USB_Success) {
            log_error("[Composite] VirtualCom initialization failed");
#if defined(USB_DEVICE_CONFIG_MTP) && (USB_DEVICE_CONFIG_MTP > 0U)
            MtpDeinit(&composite.mtpApp);
#endif
            goto error;
        }
    }

#if defined(USB_DEVICE_CONFIG_USE_TASK) && (USB_DEVICE_CONFIG_USE_TASK > 0U)
    if (xTaskCreate(USB_DeviceTask,                  /* pointer to the task */
                    (char const *)"usb device task", /* task name for kernel awareness debugging */
                    3072L / sizeof(portSTACK_TYPE),  /* task stack size */
                    composite.deviceHandle,          /* optional task startup argument */
                    tskIDLE_PRIORITY,                /* initial priority */
                    &composite.device_task_handle    /* optional task handle to create */
                    ) != pdPASS) {
        log_error("[Composite] Failed to create usb device task!");
        return NULL;
    }
#endif

    USB_DeviceSetIsr(true);

    log_debug("[Composite] USB initialized");
    composite.initialized = true;
    return &composite;

error:
    USB_DevicePllDeinit();
    return NULL;
}

void composite_deinit(usb_device_composite_struct_t *instance)
{
    if (!instance || !instance->initialized) {
        log_debug("[Composite] USB already deinitialized");
        return;
    }

#if defined(USB_DEVICE_CONFIG_USE_TASK) && (USB_DEVICE_CONFIG_USE_TASK > 0U)
    vTaskDelete(composite->device_task_handle);
#endif

    usb_status_t err;
    if ((err = USB_DeviceStop(instance->deviceHandle)) != kStatus_USB_Success) {
        log_error("[Composite] Device stop failed: 0x%x", err);
    }
    USB_DeviceSetIsr(false);

#if defined(USB_DEVICE_CONFIG_MTP) && (USB_DEVICE_CONFIG_MTP > 0U)
    MtpDeinit(&instance->mtpApp);
#endif

    VirtualComDeinit(&instance->cdcVcom);

    if ((err = USB_DeviceClassDeinit(CONTROLLER_ID)) != kStatus_USB_Success) {
        log_error("[Composite] Device class deinit failed: 0x%x", err);
    }

    USB_DevicePhyDeinit();
    USB_DeviceClockDeinit();
    USB_DevicePllDeinit();

    instance->initialized = false;
    log_debug("[Composite] USB deinitialized");
}
