#ifndef GAME_H_
#define GAME_H_

#include "food.h"
#include "snake.h"
#include <SFML/Graphics.hpp>

class Game
{
public:
  Game(sf::RenderWindow *window);

  void start();

private:
  void game_loop();

  Snake snake;
  sf::RenderWindow *screen;

};

#endif
