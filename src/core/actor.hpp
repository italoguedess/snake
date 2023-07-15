// Beginning and libraries

#ifndef ACTOR_HPP
#define ACTOR_HPP
#include <array>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ranges>

// Actor_Controls Interface
// Defining the available behaviours the actor will have.


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

// Actor class

class Actor : public Actor_Controls
{

// Attributes

private:
  // the direction in which the snake will move
  char direction = 'd';
  // Actor's sprite
  std::vector<sf::Sprite> sprite;
  // checks if the snake isn't turning on itself
  bool is_snake_turning_on_itself(char new_direction);

// Declarations

public:
  Actor();
  // getter an setter methods
  sf::Vector2f get_position();
  void set_position(sf::Vector2f new_position);
  char get_direction();
  // set_direction checkes if the direction given is a valid one
  // and if the snake isn't turning on itself
  void set_direction(char new_direction);
  sf::Sprite get_sprite();
  void set_sprite(sf::Sprite new_sprite);
  std::vector<sf::Sprite> get_vector_sprite();
  void set_vector_sprite(std::vector<sf::Sprite> new_vector_sprite);

  void grow();

// Interface implementation

// snake moving methods
  virtual void point_left() override {this->set_direction('a');}
  virtual void point_up() override {this->set_direction('w');}
  virtual void point_right() override {this->set_direction('d');}
  virtual void point_down() override {this->set_direction('s');}
  virtual void move(const int move_step = 1) override
  {
    // offsets the position according to the direction
    if(move_step <= 0)
      std::cout << "in actor::move parameter move_step must be >= 0!" << std::endl;

    auto actor_body = this->sprite | std::views::drop(1) | std::views::reverse;
    // moves actor from back to front
    for(int i = 0; i < actor_body.size(); i++)
      //
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
