#ifndef SNAKE_H_
#define SNAKE_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Snake
{

public:

  Snake(sf::RenderWindow *);

  sf::RectangleShape show_snake();
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
