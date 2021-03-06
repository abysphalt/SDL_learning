 #include <cstdlib>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <sstream>
 #include <limits>
 #include <SDL2/SDL.h>

 SDL_Window* g_pWindow = 0;
 SDL_Renderer* g_pRenderer = 0;


 int main()
 {
      if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
      {
        g_pWindow = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
      }

      if(g_pWindow !=0)
      {
        g_pRenderer= SDL_CreateRenderer(g_pWindow, -1, 0 );
      }
      else
      {
        return 1;
      }

      // INIT succeed
      SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
      SDL_RenderClear(g_pRenderer);
      SDL_RenderPresent(g_pRenderer);

      SDL_Delay(5000);

      SDL_Quit();




   return 0;
 }
