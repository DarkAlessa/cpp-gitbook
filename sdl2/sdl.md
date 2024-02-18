// Keywords
`Blitting`
`Surface`
`Texture`

// note 1 -------------------------------------------------
SDL_Surface   // เป็น software rendering ใช้ RAM  (ใช้ CPU) *ช้ากว่า
SDL_Texture   // เป็น hardware rendering ใช้ VRAM (ใช้ GPU) *เร็วกว่า

// note 2 -------------------------------------------------
1) SDL_UpdateWindowSurface() ใช้กับ SDL_Surface
Example:
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* img = NULL;

window = SDL_CreateWindow(...);
screenSurface = SDL_GetWindowSurface(window);
img = SDL_LoadBMP("example.bmp");

SDL_BlitSurface(img, NULL, window, NULL);
SDL_UpdateWindowSurface(window);

//////////////////////////////////////////
2) SDL_RenderPresent()       ใช้กับ SDL_Texture
Example:
  SDL_Renderer* renderer = NULL;
  renderer = SDL_CreateRenderer(...);
  SDL_RenderPresent(renderer);

```