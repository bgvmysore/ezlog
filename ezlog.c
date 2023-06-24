#include "ezlog.h"
#include <stdarg.h>
#include <stdlib.h>

#ifndef EZLOG_NO_COLORS
    #define COLOR_TEXT_BEGIN(stream, x) (fprintf(stream, "\033[%dm", x))
    #define COLOR_TEXT_END(stream)  (fprintf(stream, "\033[39m"))
#else
    #define COLOR_TEXT_BEGIN(stream, x)
    #define COLOR_TEXT_END(stream)
#endif

enum ezlog_term_colors {
    EZLOG_RED    = 31,
    EZLOG_GREEN  = 32,
    EZLOG_YELLOW = 33,
    EZLOG_BLUE   = 34,
    EZLOG_DEFCOL = 39
};

int ezlog_eprint(FILE* stream, const char* _fmt, ...) {
    int result = 0;

    va_list args;
    va_start(args, _fmt);

    COLOR_TEXT_BEGIN(stream, EZLOG_RED);
    result += fprintf(stream, EZLOG_ERROR_PREFIX);
    result += vfprintf(stream, _fmt, args);
    COLOR_TEXT_END(stream);

    va_end(args);

    return result;
}

int ezlog_wprint(FILE* stream, const char* _fmt, ...) {
    int result = 0;

    va_list args;
    va_start(args, _fmt);

    COLOR_TEXT_BEGIN(stream, EZLOG_YELLOW);
    result += fprintf(stream, EZLOG_WARN_PREFIX);
    result += vfprintf(stream, _fmt, args);
    COLOR_TEXT_END(stream);

    va_end(args);

    return result;
}

int ezlog_iprint(FILE* stream, const char* _fmt, ...) {
    int result = 0;

    va_list args;
    va_start(args, _fmt);

    COLOR_TEXT_BEGIN(stream, EZLOG_BLUE);
    result += fprintf(stream, EZLOG_INFO_PREFIX);
    result += vfprintf(stream, _fmt, args);
    COLOR_TEXT_END(stream);

    va_end(args);

    return result;
}

int ezlog_dprint(FILE* stream, const char* _fmt, ...) {
    int result = 0;

    va_list args;
    va_start(args, _fmt);

    COLOR_TEXT_BEGIN(stream, EZLOG_GREEN);
    result += fprintf(stream, EZLOG_DEBUG_PREFIX);
    result += vfprintf(stream, _fmt, args);
    COLOR_TEXT_END(stream);

    va_end(args);

    return result;
}
