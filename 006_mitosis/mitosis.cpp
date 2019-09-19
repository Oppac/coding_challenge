#include <random>
#include <vector>

#include <SFML/Graphics.hpp>

class Cell
{
  public:
    sf::RenderWindow *screen;
    sf::CircleShape cell_shape;
    float pos_x, pos_y;
    int c_red, c_green, c_blue;

    Cell(sf::RenderWindow *window, int radius=20)
    {
      screen = window;
      cell_shape = sf::CircleShape(radius);
      std::random_device rd;
      std::mt19937 gen(rd());
      pos_x = std::uniform_real_distribution<float> (0, screen->getSize().x)(gen);
      pos_y = std::uniform_real_distribution<float> (0, screen->getSize().y)(gen);

      c_red = std::uniform_real_distribution<float> (0, 255)(gen);
      c_green = std::uniform_real_distribution<float> (0, 255)(gen);
      c_red = std::uniform_real_distribution<float> (0, 255)(gen);
    }

    Cell(sf::RenderWindow *window, int radius, float pos_x, float pos_y,
         int c_red, int c_green, int c_blue)
    {
      screen = window;
      cell_shape = sf::CircleShape(radius);
      this->pos_x = pos_x;
      this->pos_y = pos_y;

      this->c_red = c_red;
      this->c_green = c_green;
      this->c_red = c_blue;
    }

    void show()
    {
      cell_shape.setOrigin(cell_shape.getRadius(), cell_shape.getRadius());
      cell_shape.setPosition(pos_x, pos_y);

      cell_shape.setFillColor(sf::Color(c_red, c_green, c_blue));
      cell_shape.setOutlineThickness(2);
      cell_shape.setOutlineColor(sf::Color(255, 255, 255));
      screen->draw(cell_shape);
    }
};

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Mitosis");

  int speed = 1;
  std::vector<Cell*> cells;
  cells.push_back(new Cell(&window));

  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
        sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);
        sf::Vector2f mouse_pos = window.mapPixelToCoords(pixel_pos);
        for (auto& cell: cells)
        {
          if (cell->cell_shape.getGlobalBounds().contains(mouse_pos))
          ;
        }
      }
    }

    cells[0]->show();
    window.display();
  }
}
