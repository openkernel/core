/*
 * Logger.hpp
 *
 *  Created on: Aug 17, 2016
 *      Author: vasu
 */

#ifndef CORE_LOGGER_HPP_
#define CORE_LOGGER_HPP_

#include <pthread.h>
#include <cstdio>
namespace okcore
{

class Logger
{
public:
    enum Level {
        OFF = 0,
        CRITICAL,
        URGENT,
        ERROR,
        WARN,
        INFO,
        DEBUG,
        FULL = 10
    };


    static void init(FILE *file=0);
    static void setLevel(Level level);
    static bool setLogFile(FILE *file);

    static void log(Level level, const char * fmt, ...);
private:
    static const int MAX_LOG_SIZE;

    static pthread_mutex_t logFileMutex;
    static FILE * logFile;
    static pid_t  PID;
    static Level logLevel;

    Logger();
    Logger(const Logger &);
    Logger& operator=(const Logger &);
    virtual ~Logger();


};

#define logDebug(format, ...)    okcore::Logger::log(okcore::Logger::DEBUG   , "%s|D|"format, __MODULE__, ##__VA_ARGS__)
#define logInfo(format, ...)     okcore::Logger::log(okcore::Logger::INFO    , "%s|I|"format, __MODULE__, ##__VA_ARGS__)
#define logWarn(format, ...)     okcore::Logger::log(okcore::Logger::WARN    , "%s|W|"format, __MODULE__, ##__VA_ARGS__)
#define logError(format, ...)    okcore::Logger::log(okcore::Logger::ERROR   , "%s|E|"format, __MODULE__, ##__VA_ARGS__)
#define logUrgent(format, ...)   okcore::Logger::log(okcore::Logger::URGENT  , "%s|U|"format, __MODULE__, ##__VA_ARGS__)
#define logCritical(format, ...) okcore::Logger::log(okcore::Logger::CRITICAL, "%s|C|"format, __MODULE__, ##__VA_ARGS__)

#ifdef DEBUG_MODULE
#define DPRINTF(format, ...) logDebug(format, ##__VA_ARGS__)
#define IPRINTF(format, ...) logInfo(format, ##__VA_ARGS__)
#define WPRINTF(format, ...) logWarn(format, ##__VA_ARGS__)
#define EPRINTF(format, ...) logError(format, ##__VA_ARGS__)
#else
#define DPRINTF(format, ...)
#define IPRINTF(format, ...)
#define WPRINTF(format, ...)
#define EPRINTF(format, ...)
#endif

} /* namespace okcore */

#endif
