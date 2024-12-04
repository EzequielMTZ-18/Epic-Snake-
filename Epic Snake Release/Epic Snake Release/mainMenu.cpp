#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>

#include "MainMenu.h"

using namespace std;


MainMenu::MainMenu(float width, float height)
{
    if (!font.loadFromFile("FuenteBits.ttf"));

    //JUGAR
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::Blue);
    mainMenu[0].setString("JUGAR");
    mainMenu[0].setCharacterSize(30);
    mainMenu[0].setPosition(100, 300);
    //SKINS
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::Black);
    mainMenu[1].setString("SKINS");
    mainMenu[1].setCharacterSize(30);
    mainMenu[1].setPosition(100, 350);
    //RANKING
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::Black);
    mainMenu[2].setString("RECORD");
    mainMenu[2].setCharacterSize(30);
    mainMenu[2].setPosition(100, 400);
    //SALIR
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::Black);
    mainMenu[3].setString("HISTORIAL");
    mainMenu[3].setCharacterSize(30);
    mainMenu[3].setPosition(100, 450);

    mainMenu[4].setFont(font);
    mainMenu[4].setFillColor(Color::Black);
    mainMenu[4].setString("SALIR");
    mainMenu[4].setCharacterSize(30);
    mainMenu[4].setPosition(100, 500);

    MainMenuSelected = 0;
}

MainMenu::~MainMenu()
{

}

void MainMenu::draw(RenderWindow& window) {
    for (int i = 0; i < Max_main_menu; i++) {
        window.draw(mainMenu[i]);
    }
}

//MOVER ARRIBA
void MainMenu::MoveUp()
{
    if (MainMenuSelected - 1 >= 0) {
        mainMenu[MainMenuSelected].setFillColor(Color::Black);

        MainMenuSelected--;
        if (MainMenuSelected == -1) {
            MainMenuSelected = 4;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}

//MOVER ABAJO
void MainMenu::MoveDown()
{
    if (MainMenuSelected + 1 <= Max_main_menu)
    {
        mainMenu[MainMenuSelected].setFillColor(Color::Black);
        MainMenuSelected++;
        if (MainMenuSelected == 5)
        {
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);

    }
}
