EZLOG_ROOT ?= ..
EZLOG_LIB_DIR ?= $(EZLOG_ROOT)/lib
EZLOG_INCLUDE_DIR ?= $(EZLOG_ROOT)/

simple_logs.out: simple_logs.c
	gcc -Wall -Wextra -std=c99 -I$(EZLOG_INCLUDE_DIR) -o$@ $^ -L$(EZLOG_LIB_DIR) -l:libezlog.a
