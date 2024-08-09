//
// Created by minh on 7/31/2024.
//

#include "logger.h"

void CLogger::setLogLevel(const LogLevel &level) {
    if(level == LogLevel::INFO) {
        logger->set_level(spdlog::level::info);
        console_logger->set_level(spdlog::level::info);
    }else {
        logger->set_level(spdlog::level::debug);
        console_logger->set_level(spdlog::level::debug);
    }
}

void CLogger::addDebugLog(const std::string &message, const char *file, int line, const char *func) {
    logger->log(spdlog::source_loc{file, line, func}, spdlog::level::debug, message);
    console_logger->log(spdlog::source_loc{file, line, func}, spdlog::level::debug, message);
}

void CLogger::addInfoLog(const std::string &message, const char *file, int line, const char *func) {
    logger->log(spdlog::source_loc{file, line, func}, spdlog::level::info, message);
    console_logger->log(spdlog::source_loc{file, line, func}, spdlog::level::info, message);
}
