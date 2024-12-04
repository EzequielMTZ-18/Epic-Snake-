#ifndef SKINSELEC_H_INCLUDED
#define SKINSELEC_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define Max_skin_menu 4



using namespace std;
using namespace sf;

class SkinMenu
{
public:
    SkinMenu(float width, float height);
    ~SkinMenu();

    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int SkinMenuPressed() {
        return SkinMenuSelected;
    }
private:
    int SkinMenuSelected;
    Font font;
    Text skinMenu[Max_skin_menu];

};

SkinMenu::SkinMenu(float width, float height)
{
    if (!font.loadFromFile("FuenteBits.ttf"));

    //JUGAR
    skinMenu[0].setFont(font);
    skinMenu[0].setFillColor(Color::Blue);
    skinMenu[0].setString("VERDE");
    skinMenu[0].setCharacterSize(30);
    skinMenu[0].setPosition(150, 250);
    //SKINS
    skinMenu[1].setFont(font);
    skinMenu[1].setFillColor(Color::Magenta);
    skinMenu[1].setString("DORADO");
    skinMenu[1].setCharacterSize(30);
    skinMenu[1].setPosition(150, 350);
    //RANKING
    skinMenu[2].setFont(font);
    skinMenu[2].setFillColor(Color::Magenta);
    skinMenu[2].setString("ROJO");
    skinMenu[2].setCharacterSize(30);
    skinMenu[2].setPosition(150, 440);
    //SALIR
    skinMenu[3].setFont(font);
    skinMenu[3].setFillColor(Color::Magenta);
    skinMenu[3].setString("SALIR");
    skinMenu[3].setCharacterSize(30);
    skinMenu[3].setPosition(600, 500);

    SkinMenuSelected = 0;
}

SkinMenu::~SkinMenu()
{

}

void SkinMenu::draw(RenderWindow& window) {
    for (int i = 0; i < Max_skin_menu; i++) {
        window.draw(skinMenu[i]);
    }
}

//MOVER ARRIBA
void SkinMenu::MoveUp()
{
    if (SkinMenuSelected - 1 >= 0) {
        skinMenu[SkinMenuSelected].setFillColor(Color::Magenta);

        SkinMenuSelected--;
        if (SkinMenuSelected == -1) {
            SkinMenuSelected = 2;
        }
        skinMenu[SkinMenuSelected].setFillColor(Color::Blue);
    }
}

//MOVER ABAJO
void SkinMenu::MoveDown()
{
    if (SkinMenuSelected + 1 <= Max_skin_menu)
    {
        skinMenu[SkinMenuSelected].setFillColor(Color::Magenta);
        SkinMenuSelected++;
        if (SkinMenuSelected == 4)
        {
            SkinMenuSelected = 0;
        }
        skinMenu[SkinMenuSelected].setFillColor(Color::Blue);

    }
}


int skins() {
    sf::RenderWindow MENU(sf::VideoMode(800, 600), "SELECCION DE SKIN", Style::Default);
    SkinMenu skinMenu(MENU.getSize().x, MENU.getSize().y);
    //fondo
    RectangleShape background;
    background.setSize(Vector2f(800, 600));
    Texture Maintexture;
    Maintexture.loadFromFile("SDS.png");
    background.setTexture(&Maintexture);


    while (MENU.isOpen())
    {
        Event event;
        while (MENU.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                MENU.close();
            }

            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up)
                {
                    skinMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down)
                {
                    skinMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return)
                {


                    int x = skinMenu.SkinMenuPressed();
                    if (x == 0)///VERDE
                    {

                        return 0;
                    }
                    if (x == 1)///DORADO
                    {

                        return 1;
                    }
                    if (x == 2)///ROJO
                    {

                        return 2;
                    }
                    if (x == 3)///SALIR
                        MENU.close();
                    break;
                }
            }
        }
        MENU.clear();
        MENU.draw(background);
        skinMenu.draw(MENU);
        MENU.display();
    }
    return 0;
}

#endif // SKINSELEC_H_INCLUDED

