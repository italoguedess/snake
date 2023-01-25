#ifndef ACTOR_HPP
#define ACTOR_HPP
#include <array>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ranges>

/*
 * Class which will implement all the
 * caracteristics and behaviours of
 * the actor
 */

struct Actor_Controls
{
  // sets the direction in which the snake is headed
  virtual void point_left() = 0;
  virtual void point_up() = 0;
  virtual void point_right() = 0;
  virtual void point_down() = 0;
  // makes the snake move one step
  virtual void move(const int move_step) = 0;
};

class Actor : public Actor_Controls
{
private:
  // the direction in which the snake will move
  char direction = 'd';
  // Actor's sprite
  std::vector<sf::Sprite> sprite;
public:
  Actor();
  // getter an setter methods
  sf::Vector2f get_position();
  void set_position(sf::Vector2f new_position);
  char get_direction();
  void set_direction(char new_direction);
  sf::Sprite get_sprite();
  void set_sprite(sf::Sprite new_sprite);
  std::vector<sf::Sprite> get_vector_sprite();
  void set_vector_sprite(std::vector<sf::Sprite> new_vector_sprite);

  void grow();

  // Snake_Back_End methods
  virtual void point_left() override {this->direction = 'a';}
  virtual void point_up() override {this->direction = 'w';}
  virtual void point_right() override {this->direction = 'd';}
  virtual void point_down() override {this->direction = 's';}
  virtual void move(const int move_step = 1) override
  {
    // offsets the position according to the direction
    if(move_step <= 0)
      std::cout << "in actor::move parameter move_step must be >= 0!" << std::endl;

    auto actor_body = this->sprite | std::views::drop(1) | std::views::reverse;
    for(int i = 0; i < actor_body.size(); i++)
      // moves actor from back to front
      actor_body[i].setPosition(actor_body[i+1].getPosition());

    auto &base_sprite = this->sprite.at(0);
    switch(this->direction)
    {
    case 'w':
      base_sprite.move(0, -1*move_step);
      break;
    case 's':
      base_sprite.move(0, move_step);
      break;
    case 'a':
      base_sprite.move(-1*move_step, 0);
      break;
    case 'd':
      base_sprite.move(move_step, 0);
      break;
    }
  }

};


#endif
