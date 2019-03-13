#ifndef SNAKE_H_
#define SNAKE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

class Snake
{

public:
  Snake(sf::RenderWindow *window);

  sf::RectangleShape snake_head();
  void draw_snake();
  void move_snake();
  void new_direction(sf::Vector2<int> dir);
  void game_over();
  void extend_body();

private:

  sf::RenderWindow *screen;

  int speed;
  int snake_length;
  sf::Vector2<int> direction;
  std::vector<sf::Vector2<int>> positions;
  std::vector<sf::RectangleShape> body;
  sf::Color color_body;
  sf::Color color_head;

};

#endif
