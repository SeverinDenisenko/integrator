//
// Created by Severin on 23.09.2022.
//

#ifndef INTEGRATOR_LOGGER_H
#define INTEGRATOR_LOGGER_H

#include <stdio.h>
#include <stdlib.h>

enum LogLevel
{
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARNING = 2,
    LOG_LEVEL_INFO = 3
};

typedef enum LogLevel LogLevel;

void print_manual();

void Log(const char *msg, LogLevel level);

#if DEBUG_BUILD == 1
#define LOG_LEVEL_WARNING_ENABLED 1
#define LOG_LEVEL_INFO_ENABLED 1
#endif

#define FATAL(message) Log(message, LOG_LEVEL_FATAL)
#define ERROR(message) Log(message, LOG_LEVEL_ERROR)

#if LOG_LEVEL_INFO_ENABLED == 1
#define INFO(message) Log(message, LOG_LEVEL_INFO)
#else
#define INFO(message)
#endif

#if LOG_LEVEL_WARNING_ENABLED == 1
#define WARNING(message) Log(message, LOG_LEVEL_WARNING)
#else
#define WARNING(message)
#endif


#endif //INTEGRATOR_LOGGER_H
