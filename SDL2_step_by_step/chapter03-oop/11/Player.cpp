

void Player::load(int x, int y, int width, int height, string textureID)
{
  GameObject::load(x,y, width, height, textureID);
}

void Player::draw(SDL_Render* pRenderer)
{
  GameObject::draw(pRenderer);
}

void Player::update()
{
  m_x -= 1;
}
