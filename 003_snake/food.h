#ifndef FOOD_H_
#define FOOD_H_

#include <SFML/Graphics.hpp>
#include <random>

class Food
{
public:
  Food(sf::RenderWindow *window);
  sf::RectangleShape food_rect();
  void draw_food();
  void new_food_pos();

private:
  sf::RenderWindow *screen;
  sf::Vector2<int> position;
  sf::RectangleShape food;
  sf::Color color;
  int food_size;

  std::mt19937 gen;
  std::uniform_int_distribution<int> disx;
  std::uniform_int_distribution<int> disy;
};

#endif
