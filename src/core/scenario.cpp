#include "scenario.hpp"
#include <SFML/Graphics.hpp>

int Grid::get_grid_size(){return this->grid_size;}
void Grid::set_grid_size(int new_grid_size){this->grid_size = new_grid_size;}

sf::Sprite Grid::get_food(){return this->food;}
void Grid::set_food(sf::Sprite new_food){this->food = new_food;}

sf::Sprite Grid::get_sprite(){return this->sprite;}
void Grid::set_sprite(sf::Sprite new_sprite){this->sprite = new_sprite;}
