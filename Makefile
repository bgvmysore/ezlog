CFLAGS := -Wall -Wextra -std=c99 -O2

SRC_OBJS := obj/ezlog.o

DYNAMIC_LIB := lib/libezlog.so
STATIC_LIB := lib/libezlog.a

.PHONY:
default: dirs $(SRC_OBJS) $(DYNAMIC_LIB) $(STATIC_LIB)

$(DYNAMIC_LIB): $(SRC_OBJS)
	$(CC) -shared -o$@ $^

$(STATIC_LIB): $(SRC_OBJS)
	ar rcs $@ $^

obj/%.o: %.c
	$(CC) -fPIC $(CFLAGS) -c -o$@ $<

obj:
	mkdir obj

lib:
	mkdir lib

dirs: obj lib

clean:
	rm -rf obj
	rm -rf lib
	rm -rf examples/*.out

examples: default
	$(MAKE) -C examples

.PHONY: clean dirs examples
