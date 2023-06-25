#include "ezlog.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COLOR_TEXT_BEGIN(stream, x) (fprintf(stream, "\033[%dm", x))
#define COLOR_TEXT_END(stream)  (fprintf(stream, "\033[39m"))

#define EZLOG_ERROR_PREFIX "[ERROR] "
#define EZLOG_WARN_PREFIX  "[WARN] "
#define EZLOG_INFO_PREFIX  "[INFO] "
#define EZLOG_DEBUG_PREFIX "[DEBUG] "

enum ezlog_term_colors {
    EZLOG_COLOR_RED     = 31,
    EZLOG_COLOR_GREEN   = 32,
    EZLOG_COLOR_YELLOW  = 33,
    EZLOG_COLOR_BLUE    = 34,
    EZLOG_COLOR_DEFAULT = 39
};

const enum ezlog_term_colors EZLOG_COLORS_TABLE[EZLOG_MAX_LOGLVL] = {
    [EZLOG_ERROR] = EZLOG_COLOR_RED,
    [EZLOG_WARNING] = EZLOG_COLOR_YELLOW,
    [EZLOG_INFO] = EZLOG_COLOR_BLUE,
    [EZLOG_DEBUG] = EZLOG_COLOR_GREEN
};

const char* EZLOG_PREFIX_TABLE[EZLOG_MAX_LOGLVL] = {
    [EZLOG_ERROR] = EZLOG_ERROR_PREFIX,
    [EZLOG_WARNING] = EZLOG_WARN_PREFIX,
    [EZLOG_INFO] = EZLOG_INFO_PREFIX,
    [EZLOG_DEBUG] = EZLOG_DEBUG_PREFIX
};

int ezlog_eprint(FILE* stream, bool color_en, const char* _fmt, ...) {
    int result = 0;
    const enum ezlog_levels lvl = EZLOG_ERROR;
    va_list args;
    va_start(args, _fmt);

    if (color_en) {
        COLOR_TEXT_BEGIN(stream, EZLOG_COLORS_TABLE[lvl]);
    }

    result += fprintf(stream, "%s", EZLOG_PREFIX_TABLE[lvl]);
    result += vfprintf(stream, _fmt, args);
    result += fprintf(stream, "\n");

    if (color_en) { COLOR_TEXT_END(stream); }
    va_end(args);

    return result;

}

int ezlog_wprint(FILE* stream, bool color_en, const char* _fmt, ...) {
    int result = 0;
    const enum ezlog_levels lvl = EZLOG_WARNING;
    va_list args;
    va_start(args, _fmt);

    if (color_en) {
        COLOR_TEXT_BEGIN(stream, EZLOG_COLORS_TABLE[lvl]);
    }

    result += fprintf(stream, "%s", EZLOG_PREFIX_TABLE[lvl]);
    result += vfprintf(stream, _fmt, args);
    result += fprintf(stream, "\n");

    if (color_en) { COLOR_TEXT_END(stream); }
    va_end(args);

    return result;
}

int ezlog_iprint(FILE* stream, bool color_en, const char* _fmt, ...) {
    int result = 0;
    const enum ezlog_levels lvl = EZLOG_INFO;
    va_list args;
    va_start(args, _fmt);

    if (color_en) {
        COLOR_TEXT_BEGIN(stream, EZLOG_COLORS_TABLE[lvl]);
    }

    result += fprintf(stream, "%s", EZLOG_PREFIX_TABLE[lvl]);
    result += vfprintf(stream, _fmt, args);
    result += fprintf(stream, "\n");

    if (color_en) { COLOR_TEXT_END(stream); }
    va_end(args);

    return result;
}

int ezlog_dprint(FILE* stream, bool color_en, const char* _fmt, ...) {
    int result = 0;
    const enum ezlog_levels lvl = EZLOG_DEBUG;
    va_list args;
    va_start(args, _fmt);

    if (color_en) {
        COLOR_TEXT_BEGIN(stream, EZLOG_COLORS_TABLE[lvl]);
    }

    result += fprintf(stream, "%s", EZLOG_PREFIX_TABLE[lvl]);
    result += vfprintf(stream, _fmt, args);
    result += fprintf(stream, "\n");

    if (color_en) { COLOR_TEXT_END(stream); }
    va_end(args);

    return result;
}
