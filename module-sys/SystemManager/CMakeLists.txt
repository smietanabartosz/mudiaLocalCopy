add_library(sys-manager STATIC)

target_sources(sys-manager
    PUBLIC
        include/SystemManager/DependencyGraph.hpp
        include/SystemManager/CpuSentinel.hpp
        include/SystemManager/CpuStatistics.hpp
        include/SystemManager/SystemManagerCommon.hpp
        include/SystemManager/CpuGovernor.hpp
        include/SystemManager/PowerManager.hpp
        include/SystemManager/DeviceManager.hpp
        include/SystemManager/TaskStatistics.hpp
    
    PRIVATE
        CpuGovernor.cpp
        CpuSentinel.cpp
        LogSentinel.cpp
        GovernorSentinelOperations.cpp
        CpuStatistics.cpp
        TaskStatistics.cpp
        CpuLogPrinter.cpp
        CpuPackPrinter.cpp
        data/SystemManagerActionsParams.hpp
        DependencyGraph.cpp
        DeviceManager.cpp
        graph/TopologicalSort.cpp
        graph/TopologicalSort.hpp
        PowerManager.cpp
        SystemManagerCommon.cpp
        cpu/AlgorithmFactory.cpp
        cpu/algorithm/Algorithm.cpp
        cpu/algorithm/FrequencyHold.cpp
        cpu/algorithm/ImmediateUpscale.cpp
        cpu/algorithm/FrequencyStepping.cpp
)

target_include_directories(sys-manager
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
)

target_link_libraries(sys-manager
    PUBLIC
        apps-common
        service-evtmgr
        eventstore
        sys-service
        sys-common
    PRIVATE
        service-desktop
        msgpack11
        system-stats-sink
        Microsoft.GSL::GSL
)

if (${ENABLE_TESTS})
    add_subdirectory(tests)
endif()
