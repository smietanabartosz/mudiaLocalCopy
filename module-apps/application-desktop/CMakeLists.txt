﻿# Copyright (c) 2017-2021, Mudita Sp. z.o.o. All rights reserved.
# For licensing, see https://github.com/mudita/MuditaOS/LICENSE.md

add_library(application-desktop STATIC)

target_include_directories(application-desktop
    PRIVATE
        $<BUILD_INTERFACE:
			${CMAKE_CURRENT_SOURCE_DIR}/data
			${CMAKE_CURRENT_SOURCE_DIR}/include/application-desktop
			${CMAKE_CURRENT_SOURCE_DIR}/models
			${CMAKE_CURRENT_SOURCE_DIR}/widgets
			${CMAKE_CURRENT_SOURCE_DIR}/windows
		>
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_sources(application-desktop
	PRIVATE
		ApplicationDesktop.cpp
		data/Mmi.hpp
		data/DeadBatteryInfoWindowData.hpp
		models/ActiveNotificationsListPresenter.cpp
		models/ActiveNotificationsListPresenter.hpp
		widgets/DBNotificationsHandler.cpp
		widgets/DesktopInputWidget.cpp
		widgets/DesktopInputWidget.hpp
		windows/ChargingBatteryWindow.cpp
		windows/ChargingBatteryWindow.hpp
		windows/DeadBatteryWindow.cpp
		windows/DeadBatteryWindow.hpp
		windows/DeadBatteryInfoWindow.cpp
		windows/DesktopMainWindow.cpp
		windows/DesktopMainWindow.hpp
		windows/ClosingWindow.cpp
		windows/ClosingWindow.hpp
		windows/MenuWindow.cpp
		windows/MenuWindow.hpp
		windows/MmiInternalMsgWindow.cpp
		windows/MmiInternalMsgWindow.hpp
		windows/MmiPullWindow.cpp
		windows/MmiPullWindow.hpp
		windows/MmiPushWindow.cpp
		windows/MmiPushWindow.hpp
		windows/MmiConfirmationWindow.cpp
	PUBLIC
		include/application-desktop/ApplicationDesktop.hpp
		include/application-desktop/Constants.hpp
		include/application-desktop/DBNotificationsHandler.hpp
		include/application-desktop/Names.hpp
)

target_link_libraries(application-desktop
    PUBLIC
		app
    PRIVATE
		application-messages
		i18n
		log
		magic_enum::magic_enum
		Microsoft.GSL::GSL
		module-db
		module-gui
		module-sys
		service-appmgr
		service-cellular
		service-db
		service-time
		utils-time
		utf8
	PUBLIC
		apps-common
		module-sys
		service-desktop
)
