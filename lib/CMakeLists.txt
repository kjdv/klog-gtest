file(GLOB sources *.cc *.cpp *.c *.hh *.h)

add_library(klog_gtest
    ${sources}
)

target_link_libraries(klog_gtest
    PUBLIC Klog::klog ${GMOCK_LIBRARIES} GTest::GTest
)

