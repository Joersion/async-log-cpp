#include "AsyncLog.h"

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(gLogger, severity_logger_mt<severity_level>);
severity_logger_mt<severity_level>* AsyncLog::log_ = nullptr;

void AsyncLog::init(const std::string& name) {
    boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");
    boost::log::add_file_log(boost::log::keywords::file_name = name + "_%Y%m%d%H%M%S" + ".log",
                             boost::log::keywords::rotation_size = 500 * 1024 * 1024,
                             boost::log::keywords::time_based_rotation = rotation_at_time_point(0, 0, 0),
                             boost::log::keywords::format = "%TimeStamp% [%Severity%] %ThreadID% %Message%",
                             boost::log::keywords::min_free_space = 10 * 1024 * 1024,
                             boost::log::keywords::auto_flush = true,
                             boost::log::keywords::open_mode = std::ios::out | std::ios::app);
    boost::log::add_common_attributes();
    log_ = &(gLogger::get());
}

severity_logger_mt<severity_level>& AsyncLog::getLog() {
    if (log_) {
        return *log_;
    }
    return gLogger::get();
}