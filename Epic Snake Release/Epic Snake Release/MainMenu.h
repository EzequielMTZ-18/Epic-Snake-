#ifndef MAINMENU_H_INCLUDED
#define MAINMENU_H_INCLUDED
#include <SFML/Graphics.hpp>
#define Max_main_menu 5

using namespace std;
using namespace sf;

class MainMenu
{
public:
    MainMenu(float width, float height);
    ~MainMenu();

    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int MainMenuPressed() {
        return MainMenuSelected;
    }
private:
    int MainMenuSelected;
    Font font;
    Text mainMenu[Max_main_menu];

};


#endif // MAINMENU_H_INCLUDED
