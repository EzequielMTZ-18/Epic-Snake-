#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
//aadir en compiler settings>linker settings>" -lwinmm "

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ESC 27

using namespace std;


#include "MainMenu.h"

#include "funciones.h"
#include "fecha.h"
#include "Colisionable.h"
#include "snake.h"
#include "comida.h"
#include "Enemigo.h"
#include "Controles.h"
#include "Mapa.h"
#include "SkinSelec.h"
#include "Jugador.h"
#include "Ranking.h"

int juego(int s);

void actualizarRanking(Jugador& jugadorActual) {
        Ranking jugadorEnRanking;
        bool esNuevoRecord = true;
        int pos = 0;


        if (jugadorEnRanking.leerDeDisco(0) == 1) {
            if (jugadorActual.getPuntaje() <= jugadorEnRanking.getPuntaje()) {
                esNuevoRecord = false;
            }
        }

        if (esNuevoRecord) {
            jugadorEnRanking.setNombre(jugadorActual.getNombre());
            jugadorEnRanking.setPuntaje(jugadorActual.getPuntaje());

            jugadorEnRanking.modificarArchivo(0);
            printf("¡Nuevo récord guardado!\n");
        }

    }

int main()
{
    sf::RenderWindow MENU(sf::VideoMode(800, 600), "MENU", Style::Default);
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);
    //fondo
    RectangleShape background;
    background.setSize(Vector2f(800, 600));
    Texture Maintexture;
    Maintexture.loadFromFile("Menu.png");
    background.setTexture(&Maintexture);

    int skin = 0; ///skin de vibora
    Jugador player;
    Ranking podio;

    char n[50];
    int puntaje = 0;

    int pos = 0;


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
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return)
                {


                    int x = mainMenu.MainMenuPressed();
                    if (x == 0)///EJECUCION DE JUEGO
                    {
                        cls();
                        puntaje = juego(skin);

                        if (puntaje != 0) {
                            cls();
                            cout << "====INGRESE SU NOMBRE=====" << endl;
                            //memset(n, 0, sizeof(n));
                            //cin.getline(n, 49);

                            cargarCadena(n, 49);
                            /*player.setNombre(n);
                            player.setPuntaje(puntaje);
                            player.grabarEnDisco();
                            cout << "PUNTAJE GUARDADO!" << endl;

                            actualizarRanking(player);*/

                            if (strlen(n) == 0) {  // Validar nombre no vacío
                                cout << "Nombre vacío. Intenta nuevamente." << endl;
                                cargarCadena(n, 49);  // Vuelve a intentar si el nombre está vacío
                            }
                            
                                player.setNombre(n);
                                player.setPuntaje(puntaje);
                                player.grabarEnDisco();
                                cout << "PUNTAJE GUARDADO!" << endl;

                                actualizarRanking(player);  // Actualiza si el puntaje es nuevo récord
                            

                        }

                        /*pos = 0;
                        while (podio.leerDeDisco(pos)) {
                            if (podio.getPuntaje() != NULL) {
                                if (podio.getPuntaje() < puntaje) {
                                    podio.setNombre(n);
                                    podio.setPuntaje(puntaje);
                                    podio.modificarArchivo(pos);

                                }
                                pos++;
                            }
                        }*/
                    }
                    if (x == 1)///EJECUCION DE VENTANA SKINS
                    {

                        skin = skins();
                    }
                    if (x == 2)///EJECUCION DE VENTANA RECORD
                    {
                        cls();
                        pos = 0;
                        while (podio.leerDeDisco(pos++)) {
                            podio.Mostrar();

                        }
                    }
                    if (x == 3)///EJECUCION DE HISTORIAL
                    {
                        pos = 0;
                        cls();
                        cout << "===========HISTORIAL DE PARTIDAS ================" << endl;
                        while (player.leerDeDisco(pos)) {
                            player.Mostrar();
                            pos++;
                        }

                    }
                    if (x == 4)///SALIR
                    {
                        MENU.close();
                        break;
                    }
                }
            }
        }
        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.display();
    }
}




int juego(int skin)
{  ///inicializacion de la ventana
    std::srand((unsigned)std::time(0));///es lo mismo q time null

    //Control controller;

    sf::RenderWindow window(sf::VideoMode(800, 600), "EPIC SNAKE");//x,y
    window.setFramerateLimit(60);//limite de FPS

    //creacion de fuente para los textos
    sf::Font font;

    if (!font.loadFromFile("FuenteBits.ttf"));

    sf::Font font2;
    if (!font2.loadFromFile("arial.ttf"));


    sf::Text text, fin, esc, space, g;

    text.setFont(font);



    fin.setFont(font);
    fin.setCharacterSize(20);
    fin.setPosition(270, 200);
    fin.setString("PERDISTE");

    esc.setFont(font2);
    esc.setCharacterSize(20);
    esc.setPosition(190, 250);
    esc.setString("Presione ESC para volver al menu");

    space.setFont(font2);
    space.setCharacterSize(20);
    space.setPosition(190, 300);
    space.setString("Presione SPACE para volver a empezar");

    g.setFont(font2);
    g.setCharacterSize(20);
    g.setPosition(190, 350);
    g.setString("Presione G para anotar puntaje");



    //objetos


    Snake vibora;
    vibora.ponerTextura(skin);
    Snake vibora2[350];
    for (int c = 0;c < 350;c++) {
        vibora2[c].ponerTextura(skin);
    }


    Snake auxA[350];
    int tam = 3;

    for (int i = 0;i < tam;i++) {
        if (i == 0) { vibora2[i].setPosition(vibora.getPosition().x, vibora.getPosition().y); }
        else { vibora2[i].setPosition(vibora2[i - 1].getPosition().x - 10, vibora2[i - 1].getPosition().y); }
    }

    int check = 0;

    Comida comida;
    comida.respawn();

    Sandia sandia;
    sandia.respawn();
    int timer = 60 * 5;
    int timer2 = 60 * 0.1;

    Enemigo enemigo;
    Enemigo enemigo2;

    enemigo.respawn();
    enemigo2.respawn();

    int puntos = 0;//PUNTAJE DE JUEGO
    bool perdio = false;

    Mapa fondo;

    //-----Musica de fondo----
    sf::SoundBuffer bufferMusica;
    bufferMusica.loadFromFile("Song.wav");

    sf::Sound musica;
    musica.setBuffer(bufferMusica);
    musica.setVolume(10);
    musica.play();
    //-----SONIDO COMER------
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Plop.wav");

    sf::Sound plop;
    plop.setBuffer(buffer);
    plop.setVolume(30);
    //-----SONIDO MUERTE-------
    sf::SoundBuffer bufferDeath;
    bufferDeath.loadFromFile("Oof.wav");

    sf::Sound death;
    death.setBuffer(bufferDeath);
    death.setVolume(30);


    //--//game loop (update del juego)
    while (window.isOpen())
    {
        //ReadImput Actualizar los estados de los perifericos de entrada
        //leer la cola de mensajes
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {

                    window.close();
                }
            }
        }

        //------// CMD - EJECUTAR COMANDOS (joystick)
        if (perdio == false) { ///EL UPDATE SOLO SE REALIZARA SI PERDIO== FALSE, SI PIERDE DEJA DE HACER UPDATE POR LO TANTO SE PAUSA

//------// UPDATE - Actualiza los estados del juego
            enemigo.update();
            enemigo2.update();

            if (timer > 0) {
                timer--;
            }
            if (timer2 > 0) {
                timer2--;
            }


            for (int i = 0;i < tam;i++) {
                auxA[i].setPosition(vibora2[i].getPosition().x, vibora2[i].getPosition().y);
            }

            int p = vibora.update();

            check = 1;


            if (vibora.isColision(comida)) {
                comida.respawn();
                puntos += 10;
                plop.setPitch(.5f + (std::rand() % 5 / 5.f));//cambia el tono del plop
                plop.play();
                tam += 2;
            }

            if (timer == 0 && vibora.isColision(sandia)) {

                puntos += 20;
                timer = 60 * 5;
                sandia.respawn();
                plop.play();
                tam += 3;

            }

            if (p == 1) {
                for (int i = 0;i < tam;i++) {
                    if (i == 0) vibora2[i].setPosition(vibora.getPosition().x, vibora.getPosition().y);
                    else vibora2[i].setPosition(auxA[i - 1].getPosition().x, auxA[i - 1].getPosition().y);
                }
            }

            ///COLISION CON EL ENEMIGO O MAPA
            if (vibora.isColision(enemigo) || vibora.isColision(enemigo2) || vibora.ColisionMapa() == true) {
                perdio = true;
                death.play();
            }

            text.setString("Puntaje: " + std::to_string(puntos));///convierte los puntos INT a string

            window.clear();
        }

        else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                puntos = 0;
                tam = 3;
                enemigo.respawn();
                enemigo2.respawn();
                comida.respawn();
                sandia.respawn();
                vibora.respawn();

                for (int r = 0;r < 350;r++) {
                    vibora2[r].respawn();
                }

                perdio = false;
            }
            else {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {

                    return puntos;

                }
            }
        }
        //------// DRAW
        window.draw(fondo);
        window.draw(vibora);
        for (int i = 0;i < tam;i++) {
            window.draw(vibora2[i]);
        }
        window.draw(comida);
        window.draw(text);

        if (perdio == true) {
            window.draw(fin);
            window.draw(esc);
            window.draw(space);
            window.draw(g);

        }
        window.draw(enemigo);
        window.draw(enemigo2);

        if (timer == 0) {
            window.draw(sandia);
        }

        //------// Display - FLIP
        window.display();
        window.clear();
    }
    return 0;
}

