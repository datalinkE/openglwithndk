//
// Created by datalink on 28.01.2017.
//

#ifndef OPENGLWITHNDK_MACRO_H_H
#define OPENGLWITHNDK_MACRO_H_H

#include "platform.h"

#define DCALL()  platform::Log(platform::LOG_LEVEL_DEBUG, __func__, "CALL")
#define DEBUG(msg_macro_arg) platform::Log(platform::LOG_LEVEL_DEBUG, __func__, msg_macro_arg)
#define DEBUGF(fmt_macro_arg, msg_macro_args...) platform::Log(platform::LOG_LEVEL_DEBUG, __func__, fmt_macro_arg, msg_macro_args)
#define DFLOAT(macro_arg) DEBUGF("%s: '%f'", #macro_arg, macro_arg)
#define DINT(macro_arg) DEBUGF("%s: '%d'", #macro_arg, macro_arg)
#define DSTR(macro_arg) DEBUGF("%s: '%s'", #macro_arg, macro_arg)
#define DCSTR(macro_arg) DEBUGF("%s: '%s'", #macro_arg, macro_arg.c_str())

#endif //OPENGLWITHNDK_MACRO_H_H
