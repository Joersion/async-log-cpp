#pragma once

#include <boost/function.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/trivial.hpp>
#include <iostream>
#include <sstream>
#include <string>

using boost::log::sinks::file::rotation_at_time_point;
using boost::log::sources::severity_logger_mt;
using boost::log::trivial::severity_level;

class AsyncLog {
public:
    AsyncLog() = default;
    ~AsyncLog() = default;

    static void init(const std::string& path);
    static severity_logger_mt<severity_level>& getLog();

private:
    static severity_logger_mt<severity_level>* log_;
};

#define LOG_LINE "[" << __FILE__ << ":" << __LINE__ << "]"
#define Log(msg) BOOST_LOG_SEV(AsyncLog::getLog(), severity_level::info) << msg;
#define LogDebug(msg) BOOST_LOG_SEV(AsyncLog::getLog(), severity_level::debug) << msg;
#define LogInfo(msg) BOOST_LOG_SEV(AsyncLog::getLog(), severity_level::info) << msg;
#define LogWarn(msg) BOOST_LOG_SEV(AsyncLog::getLog(), severity_level::warning) << msg;
#define LogError(msg) BOOST_LOG_SEV(AsyncLog::getLog(), severity_level::error) << LOG_LINE << msg;
