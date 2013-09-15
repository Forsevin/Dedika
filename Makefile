CC=g++
CFLAGS=-Iinclude
OUT=bin/dedika-run
DESTDIR=/usr/bin/

all:
	$(CC) $(CFLAGS) src/main.cpp src/Dedika.cpp -o $(OUT) `pkg-config --cflags --libs gtk+-3.0 webkitgtk-3.0 javascriptcoregtk-3.0`
install:
	@mkdir ${HOME}/.dedika
	@mkdir ${HOME}/.dedika/apps
	@mv ${OUT} /usr/bin/dedika-run
