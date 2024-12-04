#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>




using namespace sf;

class SnakeSection {

private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    //sf::Vector2f position;

    int cuerpo[250][2];

public:

    SnakeSection(int x = 1, int y = 1, int tam = 3) {

        int i = 0;
        cuerpo[i][0] = x - 1;
        cuerpo[i][1] = y;
        i++;
        if (i == tam)i = 1;

        _sprite.setPosition(x - 1, y);
        _texture.loadFromFile("SnakeBody1.png");
        _sprite.setTexture(_texture);
        _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);


    }

    //explicit SnakeSection(Vector2f starPosition);


    Vector2f getPosition();
    void setPosition(Vector2f newPosition);

    ///continuar
};



