#include <SDL2/SDL.h>
#include <stdio.h>
#include "Window.h"

SDL_Surface* walter = NULL;

int main(int argc, char* args[]) {

  if (!renderWindow()) {
    printf("There was an errror booting up the game\n");
  }

  else {
      // load.
      loadMedia();

      // Apply the image
      SDL_BlitSurface(walter, NULL, screenSurface, NULL);

      // Update the surface so it actually shows
      SDL_UpdateWindowSurface(window);

  }

  return 0;
}

