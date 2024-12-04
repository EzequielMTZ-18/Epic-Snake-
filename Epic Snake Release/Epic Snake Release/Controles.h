#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

//no utilizado aun

class Control
{
    bool botones[4];

public:
    enum class Buttons {
        Up = 0,
        Down,
        Left,
        Right,

        Button1,
        Button2,

    };

    void reset() {
        std::fill(botones, botones + 4, false);//pone todo el vector en falso
    }

    void BotonPresionado(Buttons boton)//recibe boton
    {
        botones[(int)boton] = true;
    }
    bool isPress(Buttons boton)
    {
        return botones[(int)boton];
    }
};

#endif // CONTROLES_H_INCLUDED