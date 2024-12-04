#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#include <SFML/Graphics.hpp>

class Mapa : public sf::Drawable
{
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    Mapa();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override ///dibuja personaje
    {
        target.draw(_sprite, states);
    }

};

Mapa::Mapa() {

    _sprite.setPosition(0, 100);
    _texture.loadFromFile("Pool table.png");
    _sprite.setTexture(_texture);
}


#endif // MAPA_H_INCLUDED
