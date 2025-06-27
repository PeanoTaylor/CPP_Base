#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/Category.hh>

int main() {
    try {
        log4cpp::PropertyConfigurator::configure("log4cpp.properties");
    } catch (const log4cpp::ConfigureFailure& e) {
        std::cerr << "配置加载失败: " << e.what() << std::endl;
        return -1;
    }

    log4cpp::Category& logger = log4cpp::Category::getRoot();
    logger.info("这是日志信息！");
    logger.warn("警告信息！");
    logger.error("错误信息！");
    return 0;
}
