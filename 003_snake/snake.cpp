#include "snake.h"

Snake::Snake(sf::RenderWindow *window)
{
  screen = window;
  color = sf::Color::Green;
  x_pos = screen->getSize().x / 2;
  y_pos = screen->getSize().y / 2;
  speed = 6;
  direction.x = x_pos; direction.y = y_pos;

  sf::RectangleShape rectangle(sf::Vector2f(x_pos, y_pos));
  rectangle.setSize(sf::Vector2f(16, 16));
  rectangle.setFillColor(color);
  body = rectangle;

}

void Snake::draw_snake()
{
  screen->draw(body);
}

void Snake::new_direction(sf::Vector2<int> dir)
{
  direction.x = dir.x * speed;
  direction.y = dir.y * speed;
}

void Snake::move_snake()
{
  x_pos += direction.x;
  y_pos += direction.y;
  body.move(direction.x , direction.y);

  if ((x_pos < 0) || (x_pos > (screen->getSize().x - 15)) ||
   (y_pos < 0) || (y_pos > (screen->getSize().y - 15)))
  {
     game_over();
  }
}

void Snake::game_over()
{
  x_pos = screen->getSize().x / 2;
  y_pos = screen->getSize().y / 2;
  body.setPosition(x_pos, y_pos);
}

void Snake::print_pos()
{
  std::cout << x_pos << std::endl;
  std::cout << y_pos << std::endl;
}
