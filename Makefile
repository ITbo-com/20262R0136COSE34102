CC = gcc
CFLAGS = -Wall -Wextra -O2

# 빌드 대상
all: build/hello build/fork

build/%: src/%.c
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf build

.PHONY: all clean
