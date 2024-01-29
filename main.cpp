#include <iostream>
#include <SFML/Graphics.hpp>
#include "System/Game.cpp"
#include "Player.cpp"

int main() {

    sf::RenderWindow window(sf::VideoMode(1200, 800), "Hello, World!");

    Game game;

    game.useWindow(window);

    game.getObjectsManager().addObject("player", Player());

    game.run();

    return 0;

}
