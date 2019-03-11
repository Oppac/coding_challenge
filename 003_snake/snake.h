#ifndef SNAKE_H_
#define SNAKE_H_

#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>

class Snake
{

public:
  Snake(sf::RenderWindow *window);

  sf::RectangleShape snake_body();
  void draw_snake();
  void move_snake();
  void new_direction(sf::Vector2<int> dir);
  void game_over();

private:

  sf::RenderWindow *screen;

  int speed;
  int snake_length;
  std::queue<sf::Vector2<int>> positions;
  sf::Vector2<int> direction;
  std::vector<sf::RectangleShape> body;
  sf::Color color_body;
  sf::Color color_head;

};

#endif
