#ifndef SNAKE_H_
#define SNAKE_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Snake
{

public:

  Snake(sf::RenderWindow *);
  int get_x_pos();
  int get_y_pos();

  sf::RectangleShape get_body();
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
