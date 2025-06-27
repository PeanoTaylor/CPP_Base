#include "log4cpp/Category.hh"         // 日志分类器接口
#include "log4cpp/Appender.hh"         // 日志输出附加器（抽象类）
#include "log4cpp/FileAppender.hh"     // 文件日志附加器
#include "log4cpp/OstreamAppender.hh"  // 控制台输出附加器
#include "log4cpp/Layout.hh"           // 日志布局接口
#include "log4cpp/BasicLayout.hh"      // 基础布局（简单格式）
#include "log4cpp/Priority.hh"         // 日志优先级（如 DEBUG, INFO, WARN 等）

int main(int argc, char** argv) {
    // 创建控制台输出附加器，并设置日志布局格式为 BasicLayout
    log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console", &std::cout);
    appender1->setLayout(new log4cpp::BasicLayout());

    // 创建文件输出附加器，日志写入 program.log 文件
    log4cpp::Appender *appender2 = new log4cpp::FileAppender("default", "program.log");
    appender2->setLayout(new log4cpp::BasicLayout());

    // 获取根日志分类器，并设置日志级别为 WARN
    log4cpp::Category& root = log4cpp::Category::getRoot();
    root.setPriority(log4cpp::Priority::WARN);
    root.addAppender(appender1);  // 将控制台输出附加器附加到根分类器

    // 创建一个名为 sub1 的子日志分类器，并附加文件输出器
    log4cpp::Category& sub1 = log4cpp::Category::getInstance(std::string("sub1"));
    sub1.addAppender(appender2);

    // === 普通日志打印（函数式） ===
    root.error("root error");  // 由于 root 的优先级是 WARN，此消息会被输出
    root.info("root info");    // 不会输出（低于 WARN）
    sub1.error("sub1 error");  // 会输出到 program.log
    sub1.warn("sub1 warn");    // 会输出到 program.log

    // === printf 风格日志打印 ===
    root.warn("%d + %d == %s ?", 1, 1, "two");  // printf 风格格式化输出

    // === 使用流式语法输出日志 ===
    root << log4cpp::Priority::ERROR << "Streamed root error";  // 流式输出 error 日志
    root << log4cpp::Priority::INFO  << "Streamed root info";   // 不输出（低于 WARN）
    sub1 << log4cpp::Priority::ERROR << "Streamed sub1 error";  // 输出到文件
    sub1 << log4cpp::Priority::WARN  << "Streamed sub1 warn";   // 输出到文件

    // === 另一种流式语法写法 ===
    root.errorStream() << "Another streamed error";  // 同样是流式 error 输出

    return 0;
}
