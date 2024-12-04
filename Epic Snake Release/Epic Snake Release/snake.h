#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include <SFML\Graphics.hpp>

///clase sfml

//MR = MOVIMIENTO REBOTE
class Snake : public sf::Drawable, public Colisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocity;
    int direccion = 0;
    int i = 1;
    sf::Vector2f v;
    int ini = 0;

public:
    ///constructor
    Snake();


    void respawn() {
        _sprite.setPosition(100, 300);
        _velocity = { 0,0 };
        _sprite.setScale(1, 1);
        _sprite.setRotation(0.f);
    }

    void setPosition(float x, float y) {
        _sprite.setPosition(x, y);
    }

    Vector2f getPosition() {
        return _sprite.getPosition();
    }

    void ponerTextura(int s) { ///COLOCA LA TEXTURA SELECCIONADA
        if (s == 0) {
            _texture.loadFromFile("Snake Head 20x20.png");
            _sprite.setTexture(_texture);
        }
        if (s == 1) {
            _texture.loadFromFile("Snake Head 20x20 Yellow.png");
            _sprite.setTexture(_texture);
        }
        if (s == 2) {
            _texture.loadFromFile("Snake Head 20x20 Red.png");
            _sprite.setTexture(_texture);
        }
    }




    int update()
    {
        //sf::Vector2f velocity = {0,0}; // movimiento estable
        //sf::sleep(sf::milliseconds(10));
        if (direccion != 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            direccion = 1;
            _velocity.y = -3;
            _velocity.x = 0;
            ini = 1;
        }
        if (direccion != 3 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            direccion = 4;
            _velocity.x = -3;
            _velocity.y = 0;
            ini = 1;
        }
        if (direccion != 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            direccion = 2;
            _velocity.y = 3;
            _velocity.x = 0;
        }
        if (direccion != 4 && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            direccion = 3;
            _velocity.x = 3;
            _velocity.y = 0;
            ini = 1;
        }

        _sprite.move(_velocity);

        return ini;

        /*float x = _velocity.x;
        float y = _velocity.y;
        static float vel[2];
        vel[0]=x;
        vel[1]=y;
        return vel;
        //MOVIMIENTO DE CABEZA
        //calculando la velocidad sabes a donde mira

        _sprite.setRotation(0.f);
        _sprite.setScale(1,1);

        if(_velocity.x<0){
            _sprite.setScale(-1,1);
        }
        if(_velocity.y>0){
            _sprite.setRotation(90.f);
        }
        if(_velocity.y<0){
            _sprite.setRotation(270.f);
        }
        */
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states)const override ///dibuja personaje
    {
        target.draw(_sprite, states);
        ///RectangleShape Serp(Vector2f(20,20));
        ///Serp.setFillColor(Color::Red);
    }


    sf::FloatRect getBounds() const override {/// const overrida indica que ese metodo esta sobreescribiendo un metodo de alguno de los padres
        return _sprite.getGlobalBounds();
    }
    void addVelocity(float velocity) { //sin usar
        _velocity.x += velocity;
        _velocity.y += velocity;
    }


    bool ColisionMapa()
    {
        if (_sprite.getGlobalBounds().left < 28) {
            return true;
        }
        if (_sprite.getGlobalBounds().top < 136) {
            return true;
        }
        if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800 - 28) { ///1:44:38
            return true;
        }
        if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600 - 33) { ///1:44:38
            return true;
        }
        return false;
    }
};

Snake::Snake()///CONSTRUCTOR
{
    _sprite.setPosition(100, 300);
    _velocity = { 0,0 };
    _texture.loadFromFile("Snake Head 20x20.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);

}













/*
class Snake1{
    ///Para guardar coord de cada del cuerpo

protected:
    int body=5;//Esto seria la cantidad de pixeles del cuerpo
    int x=10;
    int y=14;
    int cuerpo[250][2];//posicion del cuerpo
    int i=1;


public:

    ///constructor

    ///sets
    void setBody(int b){body=b;}
    void setY(int Y){y=Y;}
    void setX(int X){x=X;}

    ///gets
    int getX(){return x;}
    int getY(){return y;}
    int getBody(){return body;}

   ///getBody(int i,int j){return body[i][j];}

   void dibujar_cuerpo(int tam){

     for(int i=1;i < tam;i++){
     gotoxy(cuerpo[i][0],cuerpo[i][1]);
     cout<<(char)1;
     }

   }
   void eliminarBody(int tam){
      for(int i=1;i < tam;i++){
     gotoxy(cuerpo[i][0],cuerpo[i][1]);
     cout<<" ";
     }

   }

   void guardarPos(int x,int y,int tam){

        cuerpo[i][0]=x;
        cuerpo[i][1]=y;
        i++;
        if(i==tam)i=1;
    }

  bool Perdio(int x,int y,int tam){
  if(y==3 || y==27 || x==2 || x==119) return true;
  for(int c = tam - 1; c > 0; c--){
    if(cuerpo[c][0]== x && cuerpo[c][1]== y)return true;
  }
  return false;

}
};





*/
#endif // SNAKE_H_INCLUDED