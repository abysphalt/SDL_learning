#ifndef __GameObject__
#define __GameObject__

class GameObject
{
public:

  void load( int x, int y, int width, int height, std::string textureID);

  void draw(SDL_Renderer* pRenderer);
  {
    std::cout <<"Draw game object";
  }
  void update()
  {
    std::cout<<"Update game object";
  }
  void clean()
  {
    std::cout << "Clean game object";
  }

protected:

  std::string m_textureID;
  int m_x;
  int m_y;

  int m_width;
  int m_height;

};

#endif
