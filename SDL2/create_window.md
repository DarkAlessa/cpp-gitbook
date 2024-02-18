```
1) Include the necessary header files
  #include <SDL2/SDL.h>

2) Initialize SDL
  SDL_Init(SDL_INIT_VIDEO);

3) Create a window
  SDL_Window* window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

4) Create a renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

5) Clean up when you're done
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
```

Code Example
```cpp
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
  // Initialize SDL
  SDL_Init(SDL_INIT_VIDEO);

  // Create a window
  SDL_Window* window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

  // Create a renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  // Main loop
  bool running = true;
  while (running) {
    // Handle events
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    // Render
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  // Clean up
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
```
