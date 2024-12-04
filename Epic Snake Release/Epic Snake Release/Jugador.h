#include <cstdio>
#include <iostream>
#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS



class Jugador {

protected:
    char Nombre[50];
    int Puntaje = 0;

public:
    ///constructor
    Jugador(const char* n = "VACIO", int p = 0) {
        strcpy(Nombre, n);
        Puntaje = p;
    }
    ///sets
    void setNombre(const char* n) { strcpy(Nombre, n); }
    void setPuntaje(int p) { Puntaje = p; }
    // void setFecha(Fecha f){FechaP=f;}
     ///gets
    const char* getNombre() { return Nombre; }
    int getPuntaje() { return Puntaje; }
    //getfecha

    void Mostrar() {
        cout << "===========================" << endl;
        cout << "NOMBRE DE JUGADOR: " << Nombre << endl;
        cout << "PUNTAJE: " << Puntaje << endl;
    }

    int leerDeDisco(int pos) {
        FILE* p;
        p = fopen("historial.dat", "rb");
        if (p == NULL) p = fopen("historial.dat", "wb");
        if (p == NULL) return -1;
        fseek(p, sizeof * this * pos, 0);
        int leyo = fread(this, sizeof * this, 1, p);
        fclose(p);
        return leyo == 1 ? 1 : 0;
    }

    int grabarEnDisco() {
        FILE* p;
        p = fopen("historial.dat", "ab");
        //if (p == NULL) p = fopen("historial.dat", "wb");
        if (p == NULL) return -1;
        int grabo = fwrite(this, sizeof * this, 1, p);
        fclose(p);
        return grabo;
    }

    /*void actualizarRanking(Jugador& jugadorActual) {
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
        
    }*/

};

#endif // JUGADOR_H_INCLUDED
