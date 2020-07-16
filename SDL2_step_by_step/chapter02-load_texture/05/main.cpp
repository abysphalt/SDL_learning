 #include "Game.h"

 // The game object from the Game class
 Game* g_game = 0;

int main(int argc, char* argv[])
{

  g_game = new Game();
  g_game->init("Chapter one, DONE.", 100, 100, 800, 600, false);

  while(g_game->running())
    {
      g_game->handleEvents();
      g_game->update();
      g_game->render();
    }
    g_game->clean();
    return 0;

}
