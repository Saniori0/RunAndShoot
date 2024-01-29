//
// Created by s1ptex on 29.01.24.
//
#include <SFML/Graphics.hpp>
#include "TimeManager.cpp"
#include "Object.cpp"
#include "ObjectsManager.cpp"


class Game {

private:
    sf::RenderWindow *window;
    ObjectsManager objectsManager;
    TimeManager timeManager;

public:

    void useWindow(sf::RenderWindow &newWindow) {

        window = &newWindow;

    }

    ObjectsManager getObjectsManager() {

        return objectsManager;

    }

    TimeManager getTimeManager() {

        return timeManager;

    }


    void run() {

        while (window->isOpen()) {

            sf::Event event;

            while ((window->pollEvent(event)) & (event.type == sf::Event::Closed)) window->close();

            window->clear();

            getObjectsManager().update(window, getTimeManager());

            window->display();

        }

    }

};