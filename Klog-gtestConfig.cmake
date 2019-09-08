include("${CMAKE_CURRENT_LIST_DIR}/Klog-gtestTargets.cmake")

find_package(GTest MODULE REQUIRE)
find_library(GMOCK_LIBRARIES gmock)
find_package(Klog CONFIG REQUIRED)

