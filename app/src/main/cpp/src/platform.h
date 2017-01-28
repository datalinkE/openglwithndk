//
// Created by datalink on 28.01.2017.
//

#ifndef OPENGLWITHNDK_PLATFORM_H
#define OPENGLWITHNDK_PLATFORM_H

namespace platform {
    const int LOG_LEVEL_DEBUG = 0;
    const int LOG_LEVEL_INFO = 5;
    const int LOG_LEVEL_ERROR = 10;

    void Log(int level, const char *tag, const char *format, ...);
}
#endif //OPENGLWITHNDK_PLATFORM_H
