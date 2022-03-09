#include <SDL2/SDL.h>
#include <thread>
#include <iostream>

// Set Window width options
const int SCREEN_WIDTH = 600; 
const int SCREEN_HEIGHT = 600; 


// Initialize main window
int main() {
  // windows settings
  SDL_Window* window = NULL;

  SDL_Surface* screenSurface = NULL;

  // Log the useful errors
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Can't be initialized lmao %s\n", SDL_GetError() );
  } else {
    window = SDL_CreateWindow("Hello world!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL) {
      printf("Window couldnt be created %s\n", SDL_GetError() );
    } else {

      // Create the window
      screenSurface = SDL_GetWindowSurface(window);

      // Change the color of the game
      SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface -> format, 0xFF, 0xFF, 0xFF));

      // Update the window
      SDL_UpdateWindowSurface(window);



      // Quite function when x is pressed
      bool quit = false;

      SDL_Event e;

      while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
          if (e.type == SDL_QUIT) {
            quit = true;
          }
        }

      }
    }
  }



  SDL_DestroyWindow(window);
  SDL_Quit();


  return 0;
}