cflags=$(shell sdl2-config --cflags)
libflags=$(shell sdl2-config --libs)
build :
	cc $(cflags) -L/usr/local/lib/ -Iinclude/ -o main main.c -lSOIL $(libflags) 
