#include "Game.h"
#include <iostream>
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
              SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);
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


        // Load surface and texture
        std::cout << "loading and image\n";
        SDL_Surface* pTempSurface = SDL_LoadBMP("../assets/rider.bmp");
        m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);
        SDL_FreeSurface(pTempSurface);
        SDL_QueryTexture(m_pTexture, NULL,NULL,&m_SourceRectangle.w, &m_SourceRectangle.h);

        // change the size of the m_SourceRectangle
        //m_SourceRectangle.w = 250;
        //m_SourceRectangle.h = 100;
        // place the rectangle on specific coordinates
        //m_DestinationRectangle.x = 100;
        //m_DestinationRectangle.y = 100;
        //
        m_DestinationRectangle.x = m_SourceRectangle.x = 0;
        m_DestinationRectangle.y = m_SourceRectangle.y = 0;
        // scale the image size
        m_DestinationRectangle.w = m_SourceRectangle.w;
        m_DestinationRectangle.h = m_SourceRectangle.h;

        // end of loading, if no errors
        m_bRunning = true;
        return true;


}


void Game::render()
{
  SDL_RenderClear(m_pRenderer);
// Render the surface and texture
  SDL_RenderCopy(m_pRenderer,m_pTexture, &m_SourceRectangle,&m_DestinationRectangle);
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
{}
