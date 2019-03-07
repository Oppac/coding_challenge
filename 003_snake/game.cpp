#include "game.h"

Game::Game(sf::RenderWindow *window) : snake(window)
{
  screen = window;
}

void Game::start()
{
  game_loop();
}

void Game::game_loop()
{

  while (screen->isOpen())
  {

    screen->clear(sf::Color::Black);
    snake.draw_snake();

    sf::Event event;
    while (screen->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        screen->close();
      }
    }

    snake.move_snake();

    screen->display();
    screen->setFramerateLimit(60);
  }
}
