#include <SFML/Graphics.hpp>
#include <iostream>
#include "snake.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Snake", sf::Style::Close);
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

    window.clear(sf::Color::Black);
    the_snake->move_snake();
    the_snake->get_body().move(the_snake->get_x_pos(),the_snake->get_y_pos());
    window.draw(the_snake->get_body());
    window.display();
  }

  delete the_snake;
  return 0;
}
