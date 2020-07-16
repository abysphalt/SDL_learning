#ifndef __Player__
#define __Player__

#include "GameObject.h"

class Player : public GameObject
{
public:


  void load(int x, int y, int width, int height, std::string textureID);
  void draw(SDL_Renderer* pRenderer)
  {
    GameObject::draw();
    std::cout<<"Draw player";
  }
  void update()
  {
    std::cout<<"Update player";
    m_x =10;
    m_y= 20;
  }
  void clean()
  {
    GameObject::clean();
    std::cout<<"Clean player";
  }
}
