#include "snake.h"

Snake::Snake(sf::RenderWindow *window)
{
  screen = window;
  x_pos = 0;
  y_pos = 0;
  x_speed = 16;
  y_speed = 0;

  sf::RectangleShape rectangle(sf::Vector2f(x_pos, y_pos));
  rectangle.setSize(sf::Vector2f(16, 16));
  body = rectangle;

}

int Snake::get_x_pos()
{
  return x_pos;
}

int Snake::get_y_pos()
{
  return y_pos;
}

sf::RectangleShape Snake::get_body()
{
  return body;
}

void Snake::draw_snake()
{
  screen->draw(body);
}

void Snake::move_snake()
{
  if (x_pos < 800)
  {
    x_pos += x_speed;
    body.move(x_speed, y_speed);
  }
  else
  {
    x_pos = 0;
    body.setPosition(x_pos, y_pos);
  }
  //y_pos += y_speed;
}

void Snake::print_pos()
{
  std::cout << x_pos << std::endl;
  std::cout << y_pos << std::endl;
}
