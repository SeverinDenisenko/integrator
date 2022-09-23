//
// Created by Severin on 23.09.2022.
//

#include "logger.h"

void Log(char *msg, LogLevel level)
{
    char *LogLevelStrings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]:  ", "[INFO]:  "};

    if (level == LOG_LEVEL_FATAL)
    {
        fprintf(stderr, "%s", LogLevelStrings[level]);
        fprintf(stderr, "%s\n", msg);
        print_manual();
        exit(1);
    }
    if (level == LOG_LEVEL_ERROR)
    {
        fprintf(stderr, "%s", LogLevelStrings[level]);
        fprintf(stderr, "%s\n", msg);
    }
    if (level == LOG_LEVEL_WARNING || level == LOG_LEVEL_INFO)
    {
        fprintf(stdout, "%s", LogLevelStrings[level]);
        fprintf(stdout, "%s\n", msg);
    }
}

void print_manual()
{
    //TODO
}
