#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Snake", sf::Style::Close);
  Snake *the_snake = new Snake(&window);

  while (window.isOpen())
  {

    window.clear(sf::Color::Black);
    the_snake->draw_snake();

    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    the_snake->move_snake();

    window.display();
    window.setFramerateLimit(60);
  }

  delete the_snake;
  return 0;
}
