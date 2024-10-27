#ifndef _EZLOG_H_
#define _EZLOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define EZLOG_VERSION "v2.1.0"

enum ezlog_levels {
	EZLOG_ERROR = 0,
	EZLOG_WARNING,
	EZLOG_INFO,
	EZLOG_DEBUG,
	EZLOG_MAX_LOGLVL,
};

int ezlog_print(enum ezlog_levels loglvl, const char* _fmt, ...);

#define EZLOGE(fmtstr, ...) (void)ezlog_print(EZLOG_ERROR, fmtstr, ##__VA_ARGS__);

#define EZLOGW(fmtstr, ...) (void)ezlog_print(EZLOG_WARNING, fmtstr, ##__VA_ARGS__);

#define EZLOGI(fmtstr, ...) (void)ezlog_print(EZLOG_INFO, fmtstr, ##__VA_ARGS__);

#define EZLOGD(fmtstr, ...) (void)ezlog_print(EZLOG_DEBUG, fmtstr, ##__VA_ARGS__);

#ifdef __cplusplus
}
#endif

#endif //_EZLOG_H_
