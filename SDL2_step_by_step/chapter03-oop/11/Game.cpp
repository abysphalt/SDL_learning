#include "Game.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"

//#include "TextureManager.h"
bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
  int flags = 0;
    if(fullscreen)
      {
        flags = SDL_WINDOW_FULLSCREEN;
      }
  // initialize SDL
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "SDL init success\n";
    // init the window
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    if (m_pWindow !=0) // window init succeed
      {
        std::cout << "window creation success\n";
        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
          if(m_pRenderer !=0)//renderer init succeed
            {
              std::cout <<"renderer creation success\n";
              SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,100);
            }
            else
          {
            std::cout << "render init fail\n";
            return false;
          }
        }
        else
        {
          std::cout <<"window init fail\n";
          return false;
        }
      }
        else
        {
          std::cout <<"SDL init fail\n";
          return false;
        }

        std::cout <<"init success\n";


        /*
        // Load surface and texture
        */

        if(!TheTextureManager::Instance()-> load("../assets/animate-alpha.png", "animate", m_pRenderer))
          {
            return false;
            std::cout << "Error loading animation";
          }
          m_go.load(100,100,128,82, "animate");
          m_player.load(300,300,128,82,"animate");
        // end of loading, if no errors
        m_bRunning = true;
        return true;


}


void Game::render()
{
  SDL_RenderClear(m_pRenderer);

  /*
  //  Render the surface and texture
  */

  //m_textureManager.draw("animate",0,0,128,82,m_pRenderer);
  //m_textureManager.drawFrame("animate",100,100,128,82,1,m_currentFrame,m_pRenderer);

  TheTextureManager::Instance()->draw("animate",0,0,128,82,m_pRenderer);
  TheTextureManager::Instance()->drawFrame("animate",200,200,128,82,1,m_currentFrame,m_pRenderer);
  m_go.draw(m_pRenderer);
  m_player.draw(m_pRenderer);

  SDL_RenderPresent(m_pRenderer);


}

void Game::clean()  //SDL_Quit()
{
  std::cout <<"cleaning game\n";
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
    {
      switch (event.type)
        {
          case SDL_QUIT:
            m_bRunning = false;
            break;

          default:
            break;
        }
    }

}


void Game::update()
{
  m_currentFrame = int ((( SDL_GetTicks() / 100) %6));
  m_go.update();
  m_player.update();
}
