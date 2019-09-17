#include <random>
#include <vector>

#include <SFML/Graphics.hpp>

class Star
{
  public:
    int speed;
    int size_x, size_y;
    float x, y, z, pz;

    Star(sf::RenderWindow *window, int speed)
    {
      this->speed = speed;
      size_x = window->getSize().x;
      size_y = window->getSize().y;

      x = random_pos(0);
      y = random_pos(1);
      z = random_pos(2);
      pz = z;
    }

    float random_pos(int mode)
    {
      std::random_device rd;
      std::mt19937 gen(rd());
      if (mode == 0)
        return std::uniform_real_distribution<float> (-size_x/2, size_x/2)(gen);
      else if (mode == 1)
        return std::uniform_real_distribution<float> (-size_y/2, size_y/2)(gen);
      else
        return std::uniform_real_distribution<float> (0, size_x/2)(gen);
    }

    float mapping(float val, float in_start, float in_end,
                  float out_start, float out_end)
    {
      float slope = (out_end - out_start) / (in_end - in_start);
      return out_start + slope * (val - in_start);
    }

    void update()
    {
      z -= speed;
      if (z < 1)
      {
        z = size_x / 2;
        x = random_pos(0);
        y = random_pos(1);
        pz = z;
      }
    }

    void show(sf::RenderWindow *window)
    {
      sf::CircleShape star(3);
      star.setFillColor(sf::Color::White);

      float sx = mapping(x / z, 0, 1, 0, size_x/4) + size_x/2;
      float sy = mapping(y / z, 0, 1, 0, size_y/4) + size_y/2;
      float px = mapping(x / pz, 0, 1, 0, size_x/4) + size_x/2;
      float py = mapping(y / pz, 0, 1, 0, size_y/4) +  size_y/2;

      sf::Vertex line[] =
      {
        sf::Vertex(sf::Vector2f(sx, sy)),
        sf::Vertex(sf::Vector2f(px, py))
      };

      star.setOrigin(star.getRadius(), star.getRadius());
      star.setPosition(sx, sy);
      window->draw(star);
      window->draw(line, 2, sf::Lines);
    }
};

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Starfield");

  int speed = 1;
  int nb_stars = 200;
  std::vector<Star*> stars;
  for (int i=0; i < nb_stars; ++i)
    stars.push_back(new Star(&window, speed));

  while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);

    for (auto& star: stars)
    {
      star->update();
      star->show(&window);
    }
    window.display();
  }
}
