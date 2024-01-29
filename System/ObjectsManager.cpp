//
// Created by s1ptex on 29.01.24.
//

#include <unordered_map>
#include <list>

class Object;

class ObjectsManager{

private:
    std::unordered_map <std::string, Object> signedObjects;
    std::list <Object> unsignedObjects;

public:
    void addObject(std::string sign, Object object) {

        signedObjects.insert({sign, object});

    }

    void addObject(Object object) {

        unsignedObjects.push_back(object);

    }

    Object getObjectBySign(std::string sign) {

        return signedObjects[sign];

    }

    std::list<Object> getUnsignedObjects() {

        return unsignedObjects;

    }

    std::unordered_map<std::string, Object> getSignedObjects() {

        return signedObjects;

    }

    void updateUnsigned(sf::RenderWindow* window, TimeManager timeManager) {

        for (Object unsignedObject: unsignedObjects) {

            unsignedObject.update(window, timeManager, this);

        }

    }

    void updateSigned(sf::RenderWindow* window, TimeManager timeManager) {

        for (auto &it: signedObjects) {

            Object signedObject = it.second;
            signedObject.update(window, timeManager, this);

        }

    }

    void update(sf::RenderWindow* window, TimeManager timeManager) {

        updateSigned(window, timeManager);
        updateUnsigned(window, timeManager);

    }

};