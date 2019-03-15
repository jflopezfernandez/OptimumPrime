
SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .c .h

vpath %.c src
vpath %.h include

# Do not hard set these flags on release. Users
# expect to be able to customize program compilation,
# which these explicit flags prevent.
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -O3 -mtune=intel -march=skylake -mavx2

PROGRAM = factor

all: $(PROGRAM)

$(PROGRAM): main.o
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ -lgmp $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I include $(TARGET_ARCH) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf *.o $(PROGRAM)

