#include "snake.h"

Snake::Snake(sf::RenderWindow *window)
{
  speed = 6;
  screen = window;
  color_body = sf::Color::Green;
  color_head = sf::Color::Red;
  snake_length = 1;
  position = sf::Vector2<int>(screen->getSize().x / 2, screen->getSize().y / 2);
  direction.x = 0; direction.y = 0;

  sf::RectangleShape rectangle(sf::Vector2f(position.x, position.y));
  rectangle.setSize(sf::Vector2f(16, 16));
  rectangle.setFillColor(color_body);
  body = rectangle;
}

sf::RectangleShape Snake::snake_body()
{
  return body;
}

void Snake::draw_snake()
{
  for (int i = 0; i < snake_length; ++i)
  {
    body.setPosition(position.x, position.y);
    screen->draw(body);
  }
}

void Snake::new_direction(sf::Vector2<int> dir)
{
  direction.x = dir.x * speed;
  direction.y = dir.y * speed;
}

void Snake::move_snake()
{
  position.x += direction.x;
  position.y += direction.y;

  if ((position.x < 0) || (position.x > (screen->getSize().x - 15)) ||
   (position.y < 0) || (position.y > (screen->getSize().y - 15)))
  {
     game_over();
  }
}

void Snake::extend_body()
{
  snake_length++;
//  sf::Vector2f  = sf::Vector2f(body[snake_length-1].getPosition());
  //positions.push_back(static_cast<sf::Vector2<int>>(pos));
  //sf::RectangleShape rectangle(pos);
  //rectangle.setSize(sf::Vector2f(16, 16));
  //rectangle.setFillColor(color_body);
  //body.push_back(rectangle);
}

void Snake::game_over()
{
  snake_length = 1;
  position.x = screen->getSize().x / 2;
  position.y = screen->getSize().y / 2;
}
