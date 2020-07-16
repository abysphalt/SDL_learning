 #include <cstdlib>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <sstream>
 #include <limits>
 #include <SDL2/SDL.h>
// g_ stands for global
// the folling letter after the _ is the first letter of the type of variable
// p pointer
// b boolean
// i integer
// f float
// d double
// etc..

 SDL_Window* g_pWindow = 0;
 SDL_Renderer* g_pRenderer = 0;
 bool g_bRunning = true;

 bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
 {
   // initialize SDL
   if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
   {
     //if init succeed, create g_pWindow
     g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

     if(g_pWindow !=0)
     {
       g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
     }
     else
     {
       return false; // init failed
     }
   }
   return true;
 }

 void render()
 {
   //set render to black
   SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

   // clear the window to black
   SDL_RenderPresent(g_pRenderer);

   // show the window
   SDL_RenderPresent(g_pRenderer);

 }


void update()
{}

void handleEvents()
{}

void clean()
{}

 int main(int argc, char* argv[])
 {
      if (init("Chapter 1: SDL setting up", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN))
      {
        g_bRunning = true;
      }

      else
      {
        return 1; // init failed
      }
      // INIT succeed

      while (g_bRunning)
      {
        handleEvents();
        update();
        render();
      }
      // Cleanup SDL
      SDL_Quit();

   return 0;
 }
