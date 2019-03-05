#include "snake.h"

Snake::Snake(sf::RenderWindow *window)
{
  screen = window;
  x_pos = 0;
  y_pos = 0;
  x_speed = 16;
  y_speed = 0;

}

sf::RectangleShape Snake::show_snake()
{
  sf::RectangleShape rectangle(sf::Vector2f(x_pos, y_pos));
  rectangle.setSize(sf::Vector2f(16, 16));
  return rectangle;
}

void Snake::move_snake()
{
  if (x_pos < 800) { x_pos += x_speed; }
  else { x_pos = 0; }
  //y_pos += y_speed;
}

void Snake::print_pos()
{
  std::cout << x_pos << std::endl;
  std::cout << y_pos << std::endl;
}
