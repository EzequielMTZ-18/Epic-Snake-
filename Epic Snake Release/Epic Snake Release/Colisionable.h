#ifndef COLISIONABLE_H_INCLUDED
#define COLISIONABLE_H_INCLUDED
#include <SFML/Graphics.hpp>
class Colisionable //CLASE HERRAMIENTA PARA LAS COLISIONES
{

public:
    virtual sf::FloatRect getBounds()const = 0;
    bool isColision(Colisionable& col) const;
};

#endif // COLISIONABLE_H_INCLUDED
