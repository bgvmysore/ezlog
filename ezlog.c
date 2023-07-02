#include "ezlog.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

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
    EZLOG_COLOR_BLUE    = 36,
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

static bool g_ezlog_time_en = false;
static char g_time_buff[50] = {0};
static bool g_ezlog_color_en = true;

#define EZLOG_FUNC_IMPL do { \
    va_list args; \
    va_start(args, _fmt); \
    \
    if (g_ezlog_color_en) { \
      COLOR_TEXT_BEGIN(stream, EZLOG_COLORS_TABLE[lvl]); \
    } \
    \
    if (g_ezlog_time_en) { \
      ezlog_get_time_data(); \
      result += fprintf(stream, "[%s] ", g_time_buff); \
    } \
    \
    result += fprintf(stream, "%s", EZLOG_PREFIX_TABLE[lvl]); \
    result += vfprintf(stream, _fmt, args); \
    result += fprintf(stream, "\n"); \
    \
    if (g_ezlog_color_en) { COLOR_TEXT_END(stream); } \
    va_end(args); \
} while(0)

static void ezlog_get_time_data() {
    time_t current_time = time(NULL);
    memset(g_time_buff, 0, sizeof(g_time_buff));
    struct tm *local_time = localtime(&current_time);
    strftime(g_time_buff, sizeof(g_time_buff), "%d-%m-%Y %H:%M:%S", local_time);
}

int ezlog_eprint(FILE* stream, const char* _fmt, ...) {
    int result = 0;
    const enum ezlog_levels lvl = EZLOG_ERROR;

    EZLOG_FUNC_IMPL;

    return result;
}

int ezlog_wprint(FILE* stream, const char* _fmt, ...) {
    int result = 0;
    const enum ezlog_levels lvl = EZLOG_WARNING;

    EZLOG_FUNC_IMPL;

    return result;
}

int ezlog_iprint(FILE* stream, const char* _fmt, ...) {
    int result = 0;
    const enum ezlog_levels lvl = EZLOG_INFO;

    EZLOG_FUNC_IMPL;

    return result;
}

int ezlog_dprint(FILE* stream, const char* _fmt, ...) {
    int result = 0;
    const enum ezlog_levels lvl = EZLOG_DEBUG;

    EZLOG_FUNC_IMPL;

    return result;
}

void ezlog_init(bool time_en, bool color_en) {
    g_ezlog_time_en = time_en;
    g_ezlog_color_en = color_en;
}