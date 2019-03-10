#ifndef FOOD_H_
#define FOOD_H_

#include <SFML/Graphics.hpp>
#include <random>

class Food
{
public:
  Food(sf::RenderWindow *window);
  void draw_food();

private:
  sf::RenderWindow *screen;
  sf::Vector2<int> position;
  sf::RectangleShape food;
  sf::Color color;
};

#endif
