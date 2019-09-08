#include <gtest/gtest.h>
#include <klog/consumer.hh>
#include <klog/context.hh>
#include <iostream>
#include <sstream>

namespace {

using namespace testing;
using namespace klog;

class log_capture : public EmptyTestEventListener
{
public:
  explicit log_capture()
  {
    set_consumer(std::make_unique<ostream_consumer>(d_stream, loglevel::all, "#{thread} {severity} [{tag}] [{context}] {msg}\n"));
  }

  ~log_capture()
  {
    set_default_consumer();
  }

  void OnTestStart(const TestInfo &ti) override
  {
    reset();
  }

  void OnTestPartResult(const TestPartResult &tr) override
  {
    if (tr.failed())
      d_failure = true;
  }

  void OnTestEnd(const TestInfo &ti) override
  {
    if (d_failure)
    {
      std::cout << "*** captured logs ***" << std::endl;
      std::cout << d_stream.str() << std::flush;
    }
  }

private:
  void reset()
  {
    d_stream.str("");
    d_failure = false;
  }

  std::ostringstream d_stream;
  bool d_failure{false};
};

}

int main(int argc, char **argv)
{
  InitGoogleTest(&argc, argv);

  auto& listeners = UnitTest::GetInstance()->listeners();
  listeners.Append(new log_capture);

  return RUN_ALL_TESTS();
}
