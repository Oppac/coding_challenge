#include "food.h"

Food::Food(sf::RenderWindow *window)
{
  screen = window;
  color = sf::Color::Yellow;

  std::random_device rd;
  std::mt19937 gen(rd());
  disx = std::uniform_int_distribution<int>(0, screen->getSize().x - 16);
  disy = std::uniform_int_distribution<int>(0, screen->getSize().y - 16);
  position = sf::Vector2<int>(disx(gen), disy(gen));

  sf::RectangleShape rectangle(sf::Vector2f(position.x, position.y));
  rectangle.setSize(sf::Vector2f(16, 16));
  rectangle.setFillColor(color);
  food = rectangle;
}

sf::RectangleShape Food::food_rect()
{
  return food;
}

void Food::draw_food()
{
  food.setPosition(position.x, position.y);
  screen->draw(food);
}

void Food::new_food_pos()
{
  position = sf::Vector2<int>(disx(gen), disy(gen));
}
