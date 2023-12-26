cmake_minimum_required(VERSION 3.8)

project(systemview VERSION 1.0)

add_library(systemview)
add_library(segger::systemview ALIAS systemview)

target_include_directories(systemview
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/>
)

target_compile_options(systemview PUBLIC "-w")
target_sources(systemview
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/FreeRTOSV10/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c"
        "${CMAKE_CURRENT_LIST_DIR}/FreeRTOSV10/SEGGER_SYSVIEW_FreeRTOS.c"
        "${CMAKE_CURRENT_LIST_DIR}/SEGGER/SEGGER_SYSVIEW.c"
)

target_link_libraries(${PROJECT_NAME} PRIVATE module-os rtt)
