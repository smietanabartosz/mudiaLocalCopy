cmake_minimum_required(VERSION 3.8)

project(rtt VERSION 1.0)

add_library(rtt)
add_library(segger::rtt ALIAS rtt)

target_include_directories(rtt
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

set_property(SOURCE ${CMAKE_CURRENT_LIST_DIR}/SEGGER_RTT_ASM_ARMv7M.S PROPERTY LANGUAGE C)
target_sources(rtt
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}//SEGGER_RTT.c"
)

if((${PROJECT_TARGET} STREQUAL "TARGET_RT1051") AND (${SYSTEM_VIEW_ENABLED}))
    target_sources(${PROJECT_NAME}
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/SEGGER_RTT_ASM_ARMv7M.S"
    )
endif()
