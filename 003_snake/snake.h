#ifndef SNAKE_H_
#define SNAKE_H_

#include <SFML/Graphics.hpp>
#include <iostream>

class Snake
{

public:
  Snake(sf::RenderWindow *window);

  void draw_snake();
  void move_snake();
  void print_pos();

private:

  sf::RenderWindow *screen;

  int x_pos;
  int y_pos;
  int x_speed;
  int y_speed;
  sf::RectangleShape body;

};

#endif
