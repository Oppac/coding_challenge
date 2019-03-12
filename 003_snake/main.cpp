#include "game.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Snake", sf::Style::Close);
  Game main_game(&window);
  main_game.game_loop();
  return 0;
}
