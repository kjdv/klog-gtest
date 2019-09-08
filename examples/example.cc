#include <gtest/gtest.h>
#include <klog/logger.hh>

namespace {

klog::logger<> log("testing");

TEST(logging, failing_test)
{
  log.info("starting failing test");
  EXPECT_EQ(5, 2+2);
  log.info("ending failing test");
}

TEST(logging, succeeding_test)
{
  log.info("starting succeeding test");
  EXPECT_EQ(5, 2+3);
  log.info("ending succeeding test");
}

}
