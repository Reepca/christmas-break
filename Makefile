build :
	cc $(shell sdl-config --cflags) -o main main.c $(shell sdl-config \
	--libs)
