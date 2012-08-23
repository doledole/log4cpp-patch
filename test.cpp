#include <log4cpp/Category.hh>
#include <log4cpp/DailyRollingAppender.hh>
#include <log4cpp/AsyncDailyRollingAppender.hh>

using namespace log4cpp;

int main()
{
	// TEST DailyRollingFileAppender
	Category& root1 = Category::getRoot();
	root1.addAppender(new DailyRollingFileAppender("DailyRollingFileAppender", "test.log"));
	root1.setPriority(Priority::DEBUG);
	Category::getRoot().debugStream() << "DailyRollingFileAppender test_message" << 1;
	Category::shutdown();

	// TEST AsyncDailyRollingFileAppender
	Category& root2 = Category::getRoot();
	root2.addAppender(new AsyncDailyRollingFileAppender("AsyncDailyRollingFileAppender", "async_test.log"));
	root2.setPriority(Priority::DEBUG);
	Category::getRoot().debugStream() << "AsyncDailyRollingFileAppender test_message" << 1;
	sleep(1);	// Flush log file 20ms
	Category::shutdown();

	return 0;
}

