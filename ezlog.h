#ifndef _EZLOG_H_
#define _EZLOG_H_

#include <stdio.h>
#include <stdbool.h>

#define EZLOG_VERSION "v1.1.0"
#define EZLOG_MAX_LOGLVL (4U)

#ifndef EZLOG_CONFIG_LOGSTREAM
#define EZLOG_CONFIG_LOGSTREAM (stdout)
#endif

#ifndef EZLOG_CONFIG_COLOREN
#define EZLOG_CONFIG_COLOREN (1U)
#endif

#ifndef EZLOG_CONFIG_LOGLVL
#define EZLOG_CONFIG_LOGLVL (3U)
#endif

#ifndef EZLOG_TAG
#define EZLOG_TAG ""
#endif

enum ezlog_levels {
    EZLOG_ERROR   = 0,
    EZLOG_WARNING = 1,
    EZLOG_INFO    = 2,
    EZLOG_DEBUG   = 3
};

#define EZLOGE(fmtstr, ...) ezlog_eprint(EZLOG_CONFIG_LOGSTREAM, EZLOG_CONFIG_COLOREN, "%s: " fmtstr, (char*)EZLOG_TAG, ##__VA_ARGS__)
#define EZLOGW(fmtstr, ...) ezlog_wprint(EZLOG_CONFIG_LOGSTREAM, EZLOG_CONFIG_COLOREN, "%s: " fmtstr, (char*)EZLOG_TAG, ##__VA_ARGS__)
#define EZLOGI(fmtstr, ...) ezlog_iprint(EZLOG_CONFIG_LOGSTREAM, EZLOG_CONFIG_COLOREN, "%s: " fmtstr, (char*)EZLOG_TAG, ##__VA_ARGS__)
#define EZLOGD(fmtstr, ...) ezlog_dprint(EZLOG_CONFIG_LOGSTREAM, EZLOG_CONFIG_COLOREN, "%s: " fmtstr, (char*)EZLOG_TAG, ##__VA_ARGS__)

#ifdef EZLOG_CONFIG_NOLOGS
#undef EZLOGE
#define EZLOGE(fmtstr, ...)
#undef EZLOGW
#define EZLOGW(fmtstr, ...)
#undef EZLOGI
#define EZLOGI(fmtstr, ...)
#undef EZLOGD
#define EZLOGD(fmtstr, ...)
#endif

#if EZLOG_CONFIG_LOGLVL <= 2
#undef EZLOGD
#define EZLOGD(fmtstr, ...)
#endif

#if EZLOG_CONFIG_LOGLVL <= 1
#undef EZLOGI
#define EZLOGI(fmtstr, ...)
#endif

#if EZLOG_CONFIG_LOGLVL <= 0
#undef EZLOGW
#define EZLOGW(fmtstr, ...)
#endif

int ezlog_eprint(FILE* stream, bool color_en, const char* _fmt, ...);

int ezlog_wprint(FILE* stream, bool color_en, const char* _fmt, ...);

int ezlog_iprint(FILE* stream, bool color_en, const char* _fmt, ...);

int ezlog_dprint(FILE* stream, bool color_en, const char* _fmt, ...);

#endif //_EZLOG_H_
