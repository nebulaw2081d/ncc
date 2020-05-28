CC=gcc

ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

ncc: ncc.c
	$(CC) -g -o ncc ncc.c -lncurses

install: ncc
	cp -p ncc "$(PREFIX)/bin"
