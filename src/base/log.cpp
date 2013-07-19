#include "log.h"

namespace Base{
    /// colors
    #define __sc_color_red   "\033[0;31m"        /* 0 -> normal ;  31 -> red */
    #define __sc_color_cyan  "\033[1;36m"        /* 1 -> bold ;  36 -> cyan */
    #define __sc_color_green "\033[4;32m"        /* 4 -> underline ;  32 -> green */
    #define __sc_color_blue  "\033[9;34m"        /* 9 -> strike ;  34 -> blue */
    #define __sc_color_black  "\033[0;30m"
    #define __sc_color_brown  "\033[0;33m"
    #define __sc_color_magenta  "\033[0;35m"
    #define __sc_color_gray  "\033[0;37m"
    #define __sc_color_none   "\033[0m"        /* to flush the previous property */

    static const char *__sc_colors[] = {
	__sc_color_none, // unknown
	__sc_color_none, // default
	__sc_color_none, // verbose
	__sc_color_magenta, // debug
	__sc_color_green, // info
	__sc_color_blue, // warn
	__sc_color_red, // error
	__sc_color_cyan, // fatal
	__sc_color_gray, // silent
	__sc_color_black, 
	__sc_color_brown, 
    };

    /*
     * Send a simple string to the log.
     **/
    int __sc_log_write(int prio, const char *tag, const char *text){
	struct timeval tv;
	struct tm *tm;

	gettimeofday(&tv, NULL);
	tm=localtime(&tv.tv_sec);

	return printf("%s%d:%02d:%02d %d \t %s \t %s\n", __sc_colors[prio],
		tm->tm_hour, tm->tm_min, tm->tm_sec, tv.tv_usec, tag, text);
    }

    /*
     * A variant of __android_log_print() that takes a va_list to list
     * additional parameters.
     * */
    inline int __sc_log_vprint(int prio, const char* tag, const char* fmt, va_list ap){
	char content[4096]={0};
	vsnprintf(content, 4095, fmt, ap);
	return __sc_log_write(prio, tag, content);
    }

    /*
     * Send a formatted string to the log, used like printf(fmt,...)
     **/
    inline int __sc_log_print(int prio, const char* tag, const char* fmt, ...){
	int ret = 0;
	va_list ap; 
	va_start(ap, fmt); 
	ret = __sc_log_vprint(prio, tag, fmt, ap);
	va_end(ap);
	return ret;
    }
}
