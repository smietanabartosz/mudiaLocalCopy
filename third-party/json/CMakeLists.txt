add_library(json)
add_library(json::json ALIAS json)

if (${ENABLE_TESTS})
    add_subdirectory(test)
endif()

target_sources(json
    PRIVATE
        json11.cpp
    PUBLIC
        json11.hpp
    )

target_include_directories(json
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
