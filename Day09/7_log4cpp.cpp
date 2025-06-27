#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>


int main()
{
    
    // 创建布局，PatrrenLayout统一输出格式
    log4cpp::PatternLayout *layout1 = new log4cpp::PatternLayout();
    layout1->setConversionPattern("[%d] [%p] %c: %m%n");

    log4cpp::PatternLayout *layout2 = new log4cpp::PatternLayout();
    layout2->setConversionPattern("[%d] [%p] %c: %m%n");

    log4cpp::PatternLayout *layout3 = new log4cpp::PatternLayout();
    layout3->setConversionPattern("[%d] [%p] %c: %m%n");

    // 1.终端输出
    log4cpp::OstreamAppender *consoleAppender = new log4cpp::OstreamAppender("console", &std::cout);
    consoleAppender->setLayout(layout1);

    // 2.文件输出
    log4cpp::FileAppender *fileAppender = new log4cpp::FileAppender("file", "log_output.txt");
    fileAppender->setLayout(layout2);

    // 3. 回卷文件输出（自动滚动）
    log4cpp::RollingFileAppender* rollingAppender = new log4cpp::RollingFileAppender(
        "rolling",               // 名称
        "rolling_log.txt",       // 文件名
        5 * 1024 * 1024,         // 最大文件大小（5MB）
        3                        // 最大备份数量
    );
    rollingAppender->setLayout(layout3);

    // 获取日志分类对象
    log4cpp::Category &root = log4cpp::Category::getRoot();
    root.setPriority(log4cpp::Priority::DEBUG);

    // 输出目标
    root.addAppender(consoleAppender);
    root.addAppender(fileAppender);
    root.addAppender(rollingAppender);

    root.debug("debug message");
    root.info("info message");
    root.warn("warning message");
    root.error("error message");

    // 清理资源
    log4cpp::Category::shutdown();
    return 0;
}

