cmake_minimum_required(VERSION 3.10)

project(klog-gtest)
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
install(TARGETS klog-gtest
        EXPORT Klog-gtestTargets
        ARCHIVE DESTINATION lib COMPONENT lib
)
install(FILES Klog-gtestConfig.cmake DESTINATION share/klog-gtest)
install(FILES lib/include/.no_headers DESTINATION include/klog-gtest)

install(EXPORT Klog-gtestTargets DESTINATION share/klog-gtest NAMESPACE Klog-gtest::)
export(TARGETS klog-gtest NAMESPACE Klog-gtest:: FILE ${CMAKE_CURRENT_BINARY_DIR}/Klog-gtestTargers.cmake)
