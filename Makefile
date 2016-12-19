build :
	cc $(shell sdl2-config --cflags) -o main main.c $(shell sdl2-config \
	--libs)
