#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Enemigo : public sf::Drawable, public Colisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    int _tiempoSpawn;

    sf::Sound canal;
    sf::SoundBuffer _sonido;

    sf::Vector2f nuevaPos;
public:
    ///constructor
    Enemigo();
    void update() {
        _tiempoSpawn--;
        if (_tiempoSpawn < 0) {
            _tiempoSpawn = 60 * 5;
            nuevaPos = { std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 400 + 137 + _sprite.getGlobalBounds().height };

        }

        if (nuevaPos.x > _sprite.getPosition().x) {
            _sprite.move(5, 0);
        }
        if (nuevaPos.x < _sprite.getPosition().x) {
            _sprite.move(-5, 0);
        }
        if (nuevaPos.y > _sprite.getPosition().y) {
            _sprite.move(0, 5);
        }
        if (nuevaPos.y < _sprite.getPosition().y) {
            _sprite.move(0, -5);
        }

        //arreglo
        if (std::abs(nuevaPos.x - _sprite.getPosition().x) < 5) {
            _sprite.setPosition(nuevaPos.x, _sprite.getPosition().y);

        }

        if (std::abs(nuevaPos.y - _sprite.getPosition().y) < 5) {
            _sprite.setPosition(_sprite.getPosition().x, nuevaPos.y);
        }

    }

    void draw(sf::RenderTarget& target, sf::RenderStates states)const override ///dibuja personaje
    {
        target.draw(_sprite, states);
    }

    void respawn() {
        _sprite.setPosition(std::rand() % 700 + 300 + _sprite.getGlobalBounds().width, std::rand() % 400 + 137 + _sprite.getGlobalBounds().height);

        canal.play();
    }

    sf::FloatRect getBounds() const override {
        return _sprite.getGlobalBounds();
    }
};

Enemigo::Enemigo() {

    _texture.loadFromFile("Enemigo 30x30.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);

    _sonido.loadFromFile("Enemy Sound.wav");
    canal.setBuffer(_sonido);
    canal.setVolume(5);
}
#endif // ENEMIGO_H_INCLUDED