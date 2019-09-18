#include <random>
#include <SFML/Graphics.hpp>

class Cell
{
  public:
    sf::RenderWindow *screen;
    float pos_x, pos_y;
    int c_red, c_green, c_blue;

    Cell(sf::RenderWindow *window)
    {
      screen = window;
      std::random_device rd;
      std::mt19937 gen(rd());
      pos_x = std::uniform_real_distribution<float> (0, screen->getSize().x)(gen);
      pos_y = std::uniform_real_distribution<float> (0, screen->getSize().y)(gen);

      c_red = std::uniform_real_distribution<float> (0, 255)(gen);
      c_green = std::uniform_real_distribution<float> (0, 255)(gen);
      c_red = std::uniform_real_distribution<float> (0, 255)(gen);
    }

    void show()
    {
      sf::CircleShape cell(20);

      cell.setOrigin(cell.getRadius(), cell.getRadius());
      cell.setPosition(pos_x, pos_y);

      cell.setFillColor(sf::Color(c_red, c_green, c_blue));
      cell.setOutlineThickness(2);
      cell.setOutlineColor(sf::Color(255, 255, 255));
      screen->draw(cell);
    }
};

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Mitosis");

  Cell* cell0 = new Cell(&window);

  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    cell0->show();
    window.display();
  }
}
