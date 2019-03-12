#include "game.h"

Game::Game(sf::RenderWindow *window) : snake(window)
{
  screen = window;
}

void Game::game_loop()
{
  Food *food = new Food(screen);
  while (screen->isOpen())
  {

    screen->clear(sf::Color::Black);
    food->draw_food();
    snake.draw_snake();

    sf::Event event;
    while (screen->pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed)
      {
        sf::Vector2<int> dir;
        if (event.key.code == sf::Keyboard::Up) { dir.x = 0; dir.y = -1; }
        else if (event.key.code == sf::Keyboard::Down) { dir.x = 0; dir.y = 1; }
        else if (event.key.code == sf::Keyboard::Right) { dir.x = 1; dir.y = 0; }
        else if (event.key.code == sf::Keyboard::Left) { dir.x = -1; dir.y = 0; }
        snake.new_direction(dir);
      }
      if (event.type == sf::Event::Closed)
      {
        screen->close();
      }
    }

    snake.move_snake();

    if (snake.snake_body().getGlobalBounds().intersects(food->food_rect().getGlobalBounds()))
    {
      food->new_food_pos();
      snake.extend_body();
    }

    screen->display();
    screen->setFramerateLimit(60);
  }
}
