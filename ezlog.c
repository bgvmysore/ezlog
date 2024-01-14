#include "ezlog.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COLOR_TEXT_BEGIN(stream, x) (fprintf(stream, "\033[%dm", x))
#define COLOR_TEXT_END(stream)      (fprintf(stream, "\033[39m"))

#define EZLOG_ERROR_PREFIX "[ERROR] "
#define EZLOG_WARN_PREFIX  "[WARN] "
#define EZLOG_INFO_PREFIX  "[INFO] "
#define EZLOG_DEBUG_PREFIX "[DEBUG] "

enum ezlog_term_colors {
	EZLOG_COLOR_RED     = 31,
	EZLOG_COLOR_GREEN   = 32,
	EZLOG_COLOR_YELLOW  = 33,
	EZLOG_COLOR_BLUE    = 36,
	EZLOG_COLOR_DEFAULT = 39,
};

const enum ezlog_term_colors EZLOG_COLORS_TABLE[EZLOG_MAX_LOGLVL] = {
	[EZLOG_ERROR]   = EZLOG_COLOR_RED,
	[EZLOG_WARNING] = EZLOG_COLOR_YELLOW,
	[EZLOG_INFO]    = EZLOG_COLOR_BLUE,
	[EZLOG_DEBUG]   = EZLOG_COLOR_GREEN,
};

const char* EZLOG_PREFIX_TABLE[EZLOG_MAX_LOGLVL] = {
	[EZLOG_ERROR]   = EZLOG_ERROR_PREFIX,
	[EZLOG_WARNING] = EZLOG_WARN_PREFIX,
	[EZLOG_INFO]    = EZLOG_INFO_PREFIX,
	[EZLOG_DEBUG]   = EZLOG_DEBUG_PREFIX,
};

static FILE* g_ezlog_stream;
static bool g_ezlog_color_en = true;

int ezlog_print(enum ezlog_levels lvl, const char* _fmt, ...) {
	int result     = 0;
	g_ezlog_stream = stdout;

	va_list args;
	va_start(args, _fmt);

	if (g_ezlog_color_en)
		COLOR_TEXT_BEGIN(g_ezlog_stream, EZLOG_COLORS_TABLE[lvl]);

	result += fprintf(g_ezlog_stream, "%s", EZLOG_PREFIX_TABLE[lvl]);
	result += vfprintf(g_ezlog_stream, _fmt, args);
	result += fprintf(g_ezlog_stream, "\n");

	if (g_ezlog_color_en)
		COLOR_TEXT_END(g_ezlog_stream);

	va_end(args);

	return result;
}
