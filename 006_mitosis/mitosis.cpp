#include <random>
#include <vector>

#include <SFML/Graphics.hpp>

class Cell
{
  public:
    sf::RenderWindow *screen;
    sf::CircleShape cell_shape;
    int radius;
    sf::Vector2f position;
    sf::Vector2f direction;
    std::array<int, 3> rgb;

    Cell(sf::RenderWindow *window, int radius)
    {
      screen = window;
      this->radius = radius;

      std::random_device rd;
      std::mt19937 gen(rd());
      position.x = std::uniform_real_distribution<float> (radius, screen->getSize().x-radius)(gen);
      position.y = std::uniform_real_distribution<float> (radius, screen->getSize().y-radius)(gen);
      random_direction();

      rgb[0] = std::uniform_real_distribution<float> (0, 255)(gen);
      rgb[1] = std::uniform_real_distribution<float> (0, 255)(gen);
      rgb[2] = std::uniform_real_distribution<float> (0, 255)(gen);

      new_shape();
    }

    Cell(sf::RenderWindow *window, int radius, sf::Vector2f position,
         std::array<int, 3> rgb, sf::Vector2f direction)
    {
      screen = window;
      this->radius = radius;
      this->position = position;
      random_direction();
      this->rgb = rgb;

      new_shape();
    }

    void new_shape()
    {
      this->cell_shape = sf::CircleShape(radius);
      cell_shape.setOrigin(radius, radius);
      cell_shape.setFillColor(sf::Color(rgb[0], rgb[1], rgb[2]));
      cell_shape.setOutlineThickness(2);
      cell_shape.setOutlineColor(sf::Color(255, 255, 255));
    }

    void random_direction()
    {
      std::random_device rd;
      std::mt19937 gen(rd());
      direction.x = std::uniform_real_distribution<float> (-0.3, 0.3)(gen);
      direction.y = std::uniform_real_distribution<float> (-0.3, 0.3)(gen);
    }

    void move()
    {
      position.x += direction.x;
      position.y += direction.y;

      if ((position.x > screen->getSize().x-radius) || (position.x < radius))
        direction.x = -direction.x;
      if ((position.y > screen->getSize().y-radius) || (position.y < radius))
        direction.y = -direction.y;

      cell_shape.setPosition(position.x, position.y);
    }

};

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Mitosis");

  std::vector<Cell*> cells;
  cells.push_back(new Cell(&window, 20));

  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::MouseButtonReleased)
      {
        sf::Vector2i pixel_position = sf::Mouse::getPosition(window);
        sf::Vector2f mouse_position = window.mapPixelToCoords(pixel_position);
        for (auto& cell: cells)
        {
          if (cell->cell_shape.getGlobalBounds().contains(mouse_position))
          {
            cells.push_back(new Cell(&window, cell->radius, cell->position,
                           cell->rgb, cell->direction));
          }
        }
      }
    }

    window.clear(sf::Color::Black);

    for (auto& cell: cells)
    {
      cell->move();
      window.draw(cell->cell_shape);
    }

    window.display();
  }

  for (auto& cell: cells)
    delete cell;
}
