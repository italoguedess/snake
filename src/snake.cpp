#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
// #include <SFML/Keyboard.hpp>
#include "core/game.hpp"
#include "core/actor.hpp"
#include "core/scenario.hpp"

// ISSUE: apparently can't load a file without its complete path

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

  sf::Font font;
  if (!font.loadFromFile("/usr/share/fonts/TTF/JetBrainsMono-Bold.ttf"))
    std::cout << "Erro ao carregar a font!" << std::endl;

  sf::Text text;
  text.setFont(font);
  text.setString("Hello World!");
  text.setCharacterSize(24); // in pixels, not points!
  // set the color
  text.setFillColor(sf::Color::Red);
  // set the text style
  text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  // run the program as long as the window is open

  sf::Texture texture;
  if(!texture.loadFromFile("/home/italo/Pictures/20220313_19h52m44s_grim.png"))
    std::cout << "Erro ao carregar a textura!" << std::endl;

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(100, 100, 100, 100));
  sprite.setPosition(sf::Vector2f(10.f, 50.f));

  // Scenario scenario;
  // Scenario_Interface* scenario_interface = &scenario;
  // scenario_interface->start();

  Actor actor;
  // std::cout << actor->get_size() << std::endl;
  // Snake *actor_interface = &actor;
  // std::cout << actor_interface->get_position().at(0) << std::endl;
  // std::cout << actor_interface->get_position().at(1) << std::endl;

  while (window.isOpen())
  {
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
      if(event.type == sf::Event::KeyReleased)
      {
        switch(event.key.code)
        {
          case sf::Keyboard::W:
            break;

        }
      }

    //   switch (event.type)
    //   {
    //     case sf::Event::Closed:
    //       window.close();
    //       break;
    //     case sf::Event::KeyPressed:
    //       // does nothing yet
    //       break;
    //     default:
    //       // does nothing
    //       break;

    //   }
    }
    // clear the window with black color
    window.clear(sf::Color::Black);

    // draw everything here...
    window.draw(text);
    sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position
    window.draw(sprite);

    // end the current frame
    window.display();

    sf::sleep(sf::seconds(0.5));
  }

  return 0;
}
