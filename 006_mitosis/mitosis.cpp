#include <SFML/Graphics.hpp>

class Cell
{
  public:


    Cell()
    {

    }
};

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Mitosis");

  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.display();
  }
}
