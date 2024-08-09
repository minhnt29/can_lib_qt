//
// Created by minh on 7/31/2024.
//

#ifndef CAN_LIB_LOGGER_H
#define CAN_LIB_LOGGER_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"


#define LOG_INFO(message) CLogger::instance().addInfoLog(message, __FILE__, __LINE__, __func__)
#define LOG_DEBUG(message) CLogger::instance().addDebugLog(message, __FILE__, __LINE__, __func__)

enum class LogLevel {
    INFO,
    DEBUG
};

class CLogger {
public:
    static CLogger& instance() {
        static CLogger logger;
        return logger;
    };
    void addInfoLog(const std::string& message, const char* file, int line, const char* func);
    void addDebugLog(const std::string& message, const char* file, int line, const char* func);
    void setLogLevel(const LogLevel& level);



private:
    CLogger(){
        logger->set_pattern("[%d-%m-%Y %T.%f] [%^%l%$] [thread %t] [%s:%# %!] %v");
        console_logger->set_pattern("[%d-%m-%Y %T.%f] [%^%l%$] [thread %t] [%s:%# %!] %v");
        setLogLevel(LogLevel::INFO);
    };
    std::shared_ptr<spdlog::logger> logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
    std::shared_ptr<spdlog::logger> console_logger = spdlog::stdout_color_mt("console");

};

#endif //CAN_LIB_LOGGER_H
