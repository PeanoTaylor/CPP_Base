#include "6_logger.h"
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Category.hh>

// 初始化静态成员变量
// 初始化静态成员变量
Logger* Logger::_pInstance = nullptr;
Category* Logger::_root = nullptr;

// 构造函数
Logger::Logger(){
    PatternLayout *layout1 = new PatternLayout();
    layout1->setConversionPattern("[%d] [%p]: %m%n");

    PatternLayout *layout2 = new PatternLayout();
    layout2->setConversionPattern("[%d] [%p]: %m%n");

    // 终端输出
    OstreamAppender *consoleAppender = new OstreamAppender("console",&std::cout);
    consoleAppender->setLayout(layout1);
    // 文件输出
    FileAppender *fileAppender = new FileAppender("file","6_log.txt");
    fileAppender->setLayout(layout2);

    // 设置输出信息
    _root = &Category::getRoot();
    _root->addAppender(consoleAppender);
    _root->addAppender(fileAppender);
    _root->setPriority(Priority::DEBUG);
}

// 析构函数
Logger::~Logger(){
    if(_root){
        _root->removeAllAppenders();
    }
    Category::shutdown();// 清理资源
}

// 单例方法
Logger* Logger::getInstance() {
    if (!_pInstance) {
        _pInstance = new Logger();
    }
    return _pInstance;
}

// 单例销毁方法
void Logger::destroy(){
    if(_pInstance){
        delete _pInstance;
        _pInstance = nullptr;
    }
}

// 日志输出方法
void Logger::warn(const char* file, int line, const char* func, const char* msg) {
    _root->warn("[%s:%d:%s] %s", file, line, func, msg);
}

void Logger::error(const char* file, int line, const char* func, const char* msg) {
    _root->error("[%s:%d:%s] %s", file, line, func, msg);
}

void Logger::debug(const char* file, int line, const char* func, const char* msg) {
    _root->debug("[%s:%d:%s] %s", file, line, func, msg);
}

void Logger::info(const char* file, int line, const char* func, const char* msg) {
    _root->info("[%s:%d:%s] %s", file, line, func, msg);
}
int main()
{
    
    LOG_INFO("info message.");
    LOG_DEBUG("debug message.");
    LOG_WARN("warning message.");
    LOG_ERROR("error message.");

    // 销毁单例
    Logger::destroy();
    return 0;
}

