#include "snake.h"

const int INIT_POS = 400;

Snake::Snake(sf::RenderWindow *window)
{
  screen = window;
  x_pos = INIT_POS;
  y_pos = INIT_POS;
  speed = 6;
  direction.x = INIT_POS; direction.y = INIT_POS;

  sf::RectangleShape rectangle(sf::Vector2f(INIT_POS, INIT_POS));
  rectangle.setSize(sf::Vector2f(16, 16));
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

  if ((x_pos < 0) || (x_pos > 784) || (y_pos < 0) || (y_pos > 784))
  {
     game_over();
  }
}

void Snake::game_over()
{
  x_pos = INIT_POS;
  y_pos = INIT_POS;
  body.setPosition(x_pos, y_pos);
}

void Snake::print_pos()
{
  std::cout << x_pos << std::endl;
  std::cout << y_pos << std::endl;
}
