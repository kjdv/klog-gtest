file(GLOB sources *.cc *.cpp *.c *.hh *.h)

add_library(klog-gtest
    ${sources}
)

target_link_libraries(klog-gtest
    PUBLIC Klog::klog ${GMOCK_LIBRARIES} GTest::GTest
)

