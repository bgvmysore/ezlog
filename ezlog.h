#ifndef _EZLOG_H_
#define _EZLOG_H_

#include <stdio.h>

#define EZLOG_VERSION "v1.0.0"

enum ezlog_term_colors {
    EZLOG_RED    = 31,
    EZLOG_GREEN  = 32,
    EZLOG_YELLOW = 33,
    EZLOG_BLUE   = 34,
    EZLOG_DEFCOL = 39
};

enum ezlog_levels {
    EZLOG_ERROR   = 0,
    EZLOG_WARNING = 1,
    EZLOG_INFO    = 2,
    EZLOG_DEBUG   = 3
};

int ezlog_eprint(FILE* stream, const char* _fmt, ...);

int ezlog_wprint(FILE* stream, const char* _fmt, ...);

int ezlog_iprint(FILE* stream, const char* _fmt, ...);

int ezlog_dprint(FILE* stream, const char* _fmt, ...);

#endif //_EZLOG_H_