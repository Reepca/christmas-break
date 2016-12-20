cflags=$(shell sdl2-config --cflags)
libflags=$(shell sdl2-config --libs)
build :
	cc $(cflags) -o main main.c $(libflags)
