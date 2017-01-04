#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <GL/gl.h>
#include <SOIL.h>
#include <SDL_opengl.h>
#include "shaders.h"


#define true -1
#define false 0



// returns whether the program should stop
int handleEvent(SDL_Event theEvent)
{
     // Possible event types available at:
     // https://wiki.libsdl.org/SDL_EventType?highlight=%28%5CbCategoryEnum%5Cb%29%7C%28CategoryEvents%29
     
     switch(theEvent.type)
     {
     case SDL_KEYDOWN:
	  // Possible scancodes (physical keys) available at:
	  // https://wiki.libsdl.org/SDL_Scancode
	  // Possible keycodes (virtual keys)
	  // https://wiki.libsdl.org/SDL_Keycode
	  printf("Key down!\n");
	  switch(theEvent.key.keysym.scancode)
	  {
	  case SDL_SCANCODE_ESCAPE:
	       printf("Escape scancode down!\n");
	       return true;
	       
	  default:
	       printf("Key other than escape!\n");
	       return false;
	  }
     default:
	  printf("Event other than key!\n");
	  return false;
     }
}

int handleEvents()
{
     SDL_Event currentEvent;
     while(SDL_PollEvent(&currentEvent))
     {
	  printf("Got an event!\n");
	  int stop_loop = handleEvent(currentEvent);
	  // On windows for some reason this doesn't seem to have the intended
	  // effect of making it immediately appear in the shell. Instead it all
	  // gets written at once every 300 lines or so... weird.
	  fflush(stdin);
	  if(stop_loop)
	  {
	       return stop_loop;
	  }
     }
     return false;
}

int main(int argc, char* argv[])
{
  printf("woot\n");
  // SDL apparently has to do some setup at runtime. Mostly just being like "hey
  // operating system, I wanna do this stuff" so the operating system can say
  // "okay Johnny, as long as I know where you are."
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window* ourWindow = SDL_CreateWindow("Our window", // Window title
					    0, 0, // initial position
					    800, 800, // size
					    SDL_WINDOW_OPENGL); // self-explanatory

  /* load an image file directly as a new OpenGL texture */
  GLuint wat_titan = SOIL_load_OGL_texture("assets/test_img.bmp",
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_MIPMAPS |
					SOIL_FLAG_INVERT_Y |
					SOIL_FLAG_NTSC_SAFE_RGB |
					SOIL_FLAG_COMPRESS_TO_DXT);

  // Everything loop
  int shouldExit = false;
  while(!shouldExit)
  {
       
       /* Process all input events first. It looks like this:
        - Yo SDL, gimme an event
        - "Okay dude, here's an event"
        - Okay, is it a keyboard press?
        - "Yeah dude, it's a keyboard press"
        - Okay, is the key w?
        - "Yeah man, totally a w"
	- Awesome, that means we should start walking forward! 
       This suggests that maybe, just maybe... we should format it as a
       decision tree. */
       shouldExit = handleEvents();

       // Do recurring game logic (physics) here

       // Finally do the rendering here
       
  }
  SDL_Quit();
  return 0;
}

