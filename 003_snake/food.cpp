#include "food.h"

Food::Food(sf::RenderWindow *window)
{
  screen = window;
  color = sf::Color::Yellow;
  food_size = 16;

  std::random_device rd;
  std::mt19937 gen(rd());
  disx = std::uniform_int_distribution<int>(40, screen->getSize().x - 40);
  disy = std::uniform_int_distribution<int>(40, screen->getSize().y - 40);
  position = sf::Vector2<int>(disx(gen), disy(gen));

  sf::RectangleShape rectangle(sf::Vector2f(position.x, position.y));
  rectangle.setSize(sf::Vector2f(food_size, food_size));
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
