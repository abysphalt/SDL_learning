 #include "Game.h"

 // The game object from the Game class
 Game* g_game = 0;

int main(int argc, char* argv[])
{

  g_game = new Game();
  g_game->init("Chapter one, getting there painfully.", 100, 100, 800, 600, 0);

  while(g_game->running())
    {
      g_game->handleEvents();
      g_game->update();
      g_game->render();
    }
    g_game->clean();
    return 0;

}
