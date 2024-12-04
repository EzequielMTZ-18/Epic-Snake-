#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

class Comida : public sf::Drawable, public Colisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    ///constructor
    Comida();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override ///dibuja personaje
    {
        target.draw(_sprite, states);
    }
    void respawn() {
        _sprite.setPosition(std::rand() % 700 + 32 + _sprite.getGlobalBounds().width, std::rand() % 400 + 142 + _sprite.getGlobalBounds().height);
    }
    sf::FloatRect getBounds() const override {
        return _sprite.getGlobalBounds();
    }
};

Comida::Comida() {

    _texture.loadFromFile("Apple 20x20.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
}

class Sandia : public sf::Drawable, public Colisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    ///constructor
    Sandia();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override ///dibuja personaje
    {
        target.draw(_sprite, states);
    }
    void respawn() {
        _sprite.setPosition(std::rand() % 700 + 32 + _sprite.getGlobalBounds().width, std::rand() % 400 + 142 + _sprite.getGlobalBounds().height);
    }
    sf::FloatRect getBounds() const override {
        return _sprite.getGlobalBounds();
    }
};

Sandia::Sandia() {

    _texture.loadFromFile("Sandia 20x20.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
}























/*
class Comida{

private:
     int cx;
     int cy;
     int tipo;//diferentes tipos de comida
     int puntaje;///esto es el puntaje de cada tipo de comida, no confundir con puntaje de jugador

public:
     //constructor
     Comida(int x=(rand()%73)+1,int y=(rand()%19)+1,int p=10){
     cx=x;
     cy=y;
     puntaje=p;

     }
     //sets
     void setTipo(int t){tipo=t;}
     void setPuntaje(int p){puntaje=p;}
     void setCX(int x){cx=x;}
     void setCY(int y){cy=y;}
     //gets
     int getTipo(){return tipo;}
     int getPuntaje(){return puntaje;}
     int getCX(){return cx;}
     int getCY(){return cy;}


int spawnear_comida(Snake Serpiente){
   if(Serpiente.getX()==cx && Serpiente.getY()==cy){
     cx = (rand()%73)+1;//este +1 se puede cambiar
     cy = (rand()%19)+1;

     //Serpiente.setBody(Serpiente.getBody()+1);
     //gotoxy(1,1);
     //cout<<"BODY: "<<Serpiente.getBody();
     gotoxy(cx,cy);
     cout<<"0";
     return 1;
   }
}


};
*/
#endif // COMIDA_H_INCLUDED
