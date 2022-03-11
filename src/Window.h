#include <string>

bool renderWindow();
SDL_Surface* loadMedia(std::string path);
bool mainloop();
void close();

// Window surface

// Set the window that we will be rendering to
extern SDL_Window* window;

// The surface that is contained by the window
extern SDL_Surface* screenSurface;

// The flawless image that will be rendered
extern SDL_Surface* walter;

// you
extern SDL_Surface* ch;