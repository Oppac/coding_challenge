#include "food.h"

Food::Food(sf::RenderWindow *window)
{
  screen = window;
  color = sf::Color::Yellow;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> disx(0, screen->getSize().x - 16);
  std::uniform_int_distribution<int> disy(0, screen->getSize().y - 16);
  position = sf::Vector2<int>(disx(gen), disy(gen));

  sf::RectangleShape rectangle(sf::Vector2f(position.x, position.y));
  rectangle.setSize(sf::Vector2f(16, 16));
  rectangle.setFillColor(color);
  food = rectangle;
}

void Food::draw_food()
{
  food.setPosition(position.x, position.y);
  screen->draw(food);
}
