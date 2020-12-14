#ifndef __MYLOG_H__
#define __MYLOG_H__

#ifdef __GNUC__
// on gcc will enable warnings, just like for printf
__attribute__((__format__(__printf__, 4, 6)))
#endif

// Libraries
#include <stdio.h>
#include <time.h>
#include <stdarg.h>

// Functions
void myLog(char logLevel, char * file, int line, char append, const char * message, ...);

#endif
