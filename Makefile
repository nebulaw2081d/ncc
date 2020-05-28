CC=gcc

ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

ncc: ncc.c
	$(CC) -o ncc ncc.c

install: ncc
	cp -p ncc "$(PREFIX)/bin"
