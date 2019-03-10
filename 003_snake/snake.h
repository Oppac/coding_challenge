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
  void new_direction(sf::Vector2<int> dir);
  void game_over();
  void print_pos();

private:

  sf::RenderWindow *screen;

  int x_pos;
  int y_pos;
  int speed;
  sf::Vector2<int> direction;
  sf::RectangleShape body;
  sf::Color color;

};

#endif
