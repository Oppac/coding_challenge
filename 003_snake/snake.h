#ifndef SNAKE_H_
#define SNAKE_H_

#include <SFML/Graphics.hpp>
#include <iostream>

class Snake
{

public:
  Snake(sf::RenderWindow *window);

  sf::RectangleShape snake_body();
  void draw_snake();
  void move_snake();
  void new_direction(sf::Vector2<int> dir);
  void game_over();
  void print_pos();

private:

  sf::RenderWindow *screen;

  int speed;
  sf::Vector2<int> position;
  sf::Vector2<int> direction;
  sf::RectangleShape body;
  sf::Color color;

};

#endif
