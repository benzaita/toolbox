#ifndef __DEBUG_H__
#define __DEBUG_H__

#ifdef DEBUG

#ifdef __LINUX__
#include <stdio.h>
#define _debug(severity, module, msg, ...) \
	{ \
		if (DEBUG_##module >= DEBUG_LEVEL_##severity) { \
			fprintf(stderr, "%s():%d: " msg, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
			fflush(stderr); \
		} \
	}
#endif

#ifdef __ANDROID__
#include <android/log.h>
#define _debug(severity, module, msg, ...)  \
	{ \
		if (DEBUG_##module >= DEBUG_LEVEL_##severity) { \
			__android_log_print(ANDROID_LOG_ERROR,"EYESIGHT_ESCORE",msg,##__VA_ARGS__); \
		} \
	}
#endif

#else
#define _debug(severity, module, msg, ...)
#endif

#define debug_trace(module, msg, ...)   _debug(TRACE, module, msg, ##__VA_ARGS__)
#define debug_info(module, msg, ...)    _debug(INFO, module, msg, ##__VA_ARGS__)
#define debug_warning(module, msg, ...) _debug(WARNING, module, msg, ##__VA_ARGS__)
#define debug_error(module, msg, ...)   _debug(ERROR, module, msg, ##__VA_ARGS__)

#endif
