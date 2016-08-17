/*
 * Logger.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: vasu
 */
#include <unistd.h>
#include <stdarg.h>
#include <pthread.h>
#include <Logger.hpp>

namespace okcore {
const int Logger::MAX_LOG_SIZE = 4096;
pthread_mutex_t Logger::logFileMutex = PTHREAD_MUTEX_INITIALIZER;
FILE * Logger::logFile = stderr;

Logger::Level Logger::logLevel = Logger::ERROR;
pid_t  Logger::PID = 0;

void Logger::setLevel(Logger::Level level)
{
 logLevel = level;
}


void Logger::init(FILE *file)
{
    logFile = stderr;
    if(file) logFile = file;
    PID = getpid();
}

//private interface to log actual message
void Logger::log(Level level, const char *format, ...)
{
 if (0 == logFile || level > logLevel) return;

 char logBuffer[MAX_LOG_SIZE];
 va_list args;
 time_t timestamp;
 struct tm now;
 int tid = (int) pthread_self();

 timestamp = time(0);
 localtime_r(&timestamp, &now);

 va_start (args, format);
 vsnprintf( logBuffer, MAX_LOG_SIZE, format, args );
 va_end (args);

 //pthread_mutex_lock(&logFileMutex);
 {
 fprintf( logFile,
          "%04d%02d%02d-%02d%02d%02d %d %x %s\n" ,
          now.tm_year+1900, now.tm_mon+1, now.tm_mday,
          now.tm_hour, now.tm_min, now.tm_sec,
          PID, tid,
          logBuffer
        );

 #ifdef DEBUG_MODULE
 fflush(logFile);
 #endif
 }
 //pthread_mutex_unlock(&logFileMutex);
}

}
