#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

#define true -1
#define false 0
int main()
{
  printf("woot\n");
  // SDL apparently has to do some setup at runtime. Mostly just being like "hey
  // operating system, I wanna do this stuff" so the operating system can say
  // "okay Johnny, as long as I know where you are."
  SDL_Init(SDL_INIT_EVERYTHING);
  // Everything loop
  while(true)
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
    

       // Do recurring game logic (physics) here

       // Finally do the rendering here
       
  }
  return 0;
}

