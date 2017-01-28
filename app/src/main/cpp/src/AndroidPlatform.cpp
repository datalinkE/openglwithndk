//
// Created by datalink on 28.01.2017.
//
#include <cstdarg>
#include <android/log.h>
#include "platform.h"

namespace platform {

    void Log(int level, const char* tag, const char* format, ...) {
        va_list args;
        va_start(args, format);
        auto anLogLevel = ANDROID_LOG_DEBUG;
        switch (level) {
            case LOG_LEVEL_INFO:
                anLogLevel = ANDROID_LOG_INFO;
                break;
            case LOG_LEVEL_ERROR:
                anLogLevel = ANDROID_LOG_ERROR;
                break;
        }
        __android_log_vprint(anLogLevel, tag, format, args);
        va_end(args);
    }
}