#include "snake.h"

Snake::Snake(sf::RenderWindow *window)
{
  speed = 6;
  body_size = 30;
  frame = 0;
  screen = window;
  color_body = sf::Color::Green;
  color_head = sf::Color::Red;
  snake_length = 1;

  positions.push_back(sf::Vector2<int>(screen->getSize().x / 2, screen->getSize().y / 2));
  direction.x = 0; direction.y = 0;
  body.push_back(new_rect(true));
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
  direction.x = dir.x;
  direction.y = dir.y;
}

void Snake::move_snake()
{
  frame++;
  if (frame == speed)
  {
    for (int i = snake_length; i > 0; --i)
    {
      positions[i].x = positions[i-1].x;
      positions[i].y = positions[i-1].y;
    }
    frame = 0;
  }

  positions[0].x += direction.x * speed;
  positions[0].y += direction.y * speed;

  if ((positions[0].x < 0) || (positions[0].x > (screen->getSize().x - (body_size-1))) ||
   (positions[0].y < 0) || (positions[0].y > (screen->getSize().y - (body_size-1))))
  {
     game_over();
  }

  for (int i = 4; i < snake_length; ++i)
  {
    if (body[0].getGlobalBounds().intersects(body[i].getGlobalBounds()))
    {
      game_over();
    }
  }
}

void Snake::extend_body()
{
  snake_length++;
  body.push_back(new_rect(false));
}

sf::RectangleShape Snake::new_rect(bool is_head)
{
  sf::RectangleShape rectangle(sf::Vector2f(positions[0].x, positions[0].y));
  rectangle.setSize(sf::Vector2f(body_size, body_size));
  if (is_head) { rectangle.setFillColor(color_head); }
  else { rectangle.setFillColor(color_body); }
  return rectangle;
}

void Snake::game_over()
{
  snake_length = 1;
  direction.x = 0; direction.y = 0;
  positions[0].x = screen->getSize().x / 2;
  positions[0].y = screen->getSize().y / 2;
}
