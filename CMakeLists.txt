cmake_minimum_required(VERSION 3.10)

project(klog_gtest)
set(CMAKE_CXX_STANDARD 17)

include(GoogleTest)
find_package(GTest MODULE REQUIRED)
find_library(GMOCK_LIBRARIES gmock)
enable_testing()


# dependencies:

find_package(Klog CONFIG REQUIRED)


add_subdirectory(lib)
add_subdirectory(examples)

# install rules
install(TARGETS klog_gtest
        EXPORT Klog_gtestTargets
        ARCHIVE DESTINATION lib COMPONENT lib
        PUBLIC_HEADER DESTINATION include/klog_gtest COMPONENT dev
)
install(FILES Klog_gtestConfig.cmake DESTINATION share/klog_gtest)

install(EXPORT Klog_gtestTargets DESTINATION share/klog_gtest NAMESPACE Klog_gtest::)
export(TARGETS klog_gtest NAMESPACE Klog_gtest:: FILE ${CMAKE_CURRENT_BINARY_DIR}/Klog_gtestTargers.cmake)
