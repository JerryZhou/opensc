#ifndef __LOG_H_
#define __LOG_H_
#include "stdinc.h"

#define  JE_LOG_TAG "OpenSC-Game"

namespace Base{
    /// log priority
    typedef enum __sc_LogPriority {
	SC_LOG_UNKNOWN = 0,
	SC_LOG_DEFAULT,    /* only for SetMinPriority() */
	SC_LOG_VERBOSE,
	SC_LOG_DEBUG,
	SC_LOG_INFO,
	SC_LOG_WARN,
	SC_LOG_ERROR,
	SC_LOG_FATAL,
	SC_LOG_SILENT,     /* only for SetMinPriority(); must be last */
    } sc_LogPriority;
    
    /*
     * Send a simple string to the log.
     **/
    int __sc_log_write(int prio, const char *tag, const char *text);

    /*
     * A variant of __android_log_print() that takes a va_list to list
     * additional parameters.
     * */
    int __sc_log_vprint(int prio, const char* tag, const char* fmt, va_list ap);

    /*
     * Send a formatted string to the log, used like printf(fmt,...)
     **/
    int __sc_log_print(int prio, const char* tag, const char* fmt, ...);
}

#ifndef LOGV
#define  LOGV(...)  Base::__sc_log_print(Base::SC_LOG_VERBOSE, JE_LOG_TAG, __VA_ARGS__)
#endif

#ifndef LOGD
#define  LOGD(...)  Base::__sc_log_print(Base::SC_LOG_DEBUG, JE_LOG_TAG, __VA_ARGS__)
#endif

#ifndef LOGI
#define  LOGI(...)  Base::__sc_log_print(Base::SC_LOG_INFO, JE_LOG_TAG, __VA_ARGS__)
#endif

#ifndef LOGW
#define  LOGW(...)  Base::__sc_log_print(Base::SC_LOG_WARN, JE_LOG_TAG, __VA_ARGS__)
#endif

#ifndef LOGE
#define  LOGE(...)  Base::__sc_log_print(Base::SC_LOG_ERROR, JE_LOG_TAG, __VA_ARGS__)
#endif

#ifndef LOGF
#define  LOGF(...)  Base::__sc_log_print(Base::SC_LOG_FATAL, JE_LOG_TAG, __VA_ARGS__)
#endif

#endif

