#include <SFML/Graphics.hpp>

#include "snake.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Snake", sf::Style::Close);
  window.setFramerateLimit(60);

  Snake *the_snake = new Snake(&window);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    the_snake->move_snake();

    window.clear(sf::Color::Black);
    window.draw(the_snake->show_snake());
    window.display();
  }

  delete the_snake;
  return 0;
}
