#include "snake.h"

Snake::Snake(sf::RenderWindow *window)
{
  speed = 6;
  screen = window;
  color_body = sf::Color::Green;
  color_head = sf::Color::Red;
  snake_length = 1;

  positions.push_back(sf::Vector2<int>(screen->getSize().x / 2, screen->getSize().y / 2));
  direction.x = 0; direction.y = 0;

  sf::RectangleShape rectangle(sf::Vector2f(positions[0].x, positions[0].y));
  rectangle.setSize(sf::Vector2f(16, 16));
  rectangle.setFillColor(color_head);
  body.push_back(rectangle);
}

sf::RectangleShape Snake::snake_head()
{
  return body[0];
}

void Snake::draw_snake()
{
  for (int i = 0; i < snake_length; ++i)
  {
    body[i].setPosition(positions[i].x, positions[i].y);
    screen->draw(body[i]);
  }
}

void Snake::new_direction(sf::Vector2<int> dir)
{
  direction.x = dir.x * speed;
  direction.y = dir.y * speed;
}

void Snake::move_snake()
{
  for (int i = snake_length; i > 0; --i)
  {
    positions[i].x = positions[i-1].x;
    positions[i].y = positions[i-1].y;
  }

  positions[0].x += direction.x;
  positions[0].y += direction.y;

  if ((positions[0].x < 0) || (positions[0].x > (screen->getSize().x - 15)) ||
   (positions[0].y < 0) || (positions[0].y > (screen->getSize().y - 15)))
  {
     game_over();
  }
}

void Snake::extend_body()
{
  snake_length++;
  sf::RectangleShape rectangle(sf::Vector2f(positions[0].x, positions[0].y));
  rectangle.setSize(sf::Vector2f(16, 16));
  rectangle.setFillColor(color_body);
  body.push_back(rectangle);
}

void Snake::game_over()
{
  snake_length = 1;
  positions[0].x = screen->getSize().x / 2;
  positions[0].y = screen->getSize().y / 2;
}
