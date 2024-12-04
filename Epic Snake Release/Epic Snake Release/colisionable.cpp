#define _CRT_SECURE_NO_WARNINGS
#include "Colisionable.h"

bool Colisionable::isColision(Colisionable& obj) const {
    return getBounds().intersects(obj.getBounds());

}
