add_catch2_executable(
    NAME
        utils-time_display
    SRCS
        unittest_TimeRangeParser.cpp
    LIBS
        utils-time
)

add_catch2_executable(
    NAME
        utils-TimeZone
    SRCS
        unittest_TimeZone.cpp
    LIBS
        utils-time
)

add_catch2_executable(
    NAME
        utils-dateCommon
    SRCS
        unittest_dateCommon.cpp
    LIBS
        utils-time
)
# time tests
add_catch2_executable(
    NAME
        utils-time
    SRCS
        unittest_time.cpp
    LIBS
        utils-time
        utf8
        module-vfs
    USE_FS
)
