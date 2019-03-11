#include "snake.h"

Snake::Snake(sf::RenderWindow *window)
{
  speed = 6;
  screen = window;
  color_body = sf::Color::Green;
  color_head = sf::Color::Red;
  snake_length = 1;
  positions.push(sf::Vector2<int>(screen->getSize().x / 2, screen->getSize().y / 2));
  direction.x = 0; direction.y = 0;

  sf::RectangleShape rectangle(sf::Vector2f(positions.front().x, positions.front().y));
  rectangle.setSize(sf::Vector2f(16, 16));
  rectangle.setFillColor(color_body);
  body.push_back(rectangle);
}

sf::RectangleShape Snake::snake_body()
{
  return body[0];
}

void Snake::draw_snake()
{
  for (int i = 0; i < snake_length; ++i)
  {
    body[0].setPosition(positions.front().x, positions.front().y);
    screen->draw(body[0]);
  }
}

void Snake::new_direction(sf::Vector2<int> dir)
{
  direction.x = dir.x * speed;
  direction.y = dir.y * speed;
}

void Snake::move_snake()
{
  positions.front().x += direction.x;
  positions.front().y += direction.y;

  if ((positions.front().x < 0) || (positions.front().x > (screen->getSize().x - 15)) ||
   (positions.front().y < 0) || (positions.front().y > (screen->getSize().y - 15)))
  {
     game_over();
  }
}

void Snake::game_over()
{
  positions.front().x = screen->getSize().x / 2;
  positions.front().y = screen->getSize().y / 2;
}
