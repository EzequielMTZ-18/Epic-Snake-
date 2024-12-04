#include <cstdio>
#include <iostream>
#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

class Ranking {

protected:
    char Nombre[50];
    int Puntaje = 0;

public:
    ///constructor
    Ranking(const char* n = "VACIO", int p = 0) {
        strcpy(Nombre, n);
        Puntaje = p;
    }
    ///sets
    void setNombre(const char* n) { strcpy(Nombre, n); }
    void setPuntaje(int p) { Puntaje = p; }

    ///gets
    const char* getNombre() { return Nombre; }
    int getPuntaje() { return Puntaje; }
    //getfecha

    void Mostrar() {
        cout << "=========PUNTAJE RECORD=============" << endl;
        cout << endl;
        cout << "NOMBRE DE JUGADOR: " << Nombre << endl;
        cout << "PUNTAJE: " << Puntaje << endl;
        cout << endl;
        cout << "====================================" << endl;
    }

    int leerDeDisco(int pos) {
        FILE* p;
        p = fopen("ranking.dat", "rb");
        if (p == NULL) p = fopen("ranking.dat", "wb");
        if (p == NULL) return -1;
        fseek(p, sizeof * this * pos, 0);
        int leyo = fread(this, sizeof * this, 1, p);
        fclose(p);
        return leyo;
    }


    int grabarEnDisco() {
        FILE* p;
        p = fopen("ranking.dat", "ab");
        if (p == NULL) p = fopen("ranking.dat", "wb");
        if (p == NULL) return -1;
        int grabo = fwrite(this, sizeof * this, 1, p);
        fclose(p);
        return grabo;
    }

    /*bool modificarArchivo(int pos) {
        FILE* p;
        bool escribio;
        p = fopen("ranking.dat", "rb+");
        if (p == NULL) p = fopen("ranking.dat", "wb");
        if (p == NULL) return false;
        fseek(p, sizeof(Ranking) * pos, 0);
        escribio = fwrite(this, sizeof(Ranking), 1, p);
        fclose(p);
        return escribio;
    }*/

    bool modificarArchivo(int pos) {
        FILE* p = fopen("ranking.dat", "rb+");
        if (p == NULL) {
            // Intenta crear el archivo solo si no existe
            p = fopen("ranking.dat", "ab+");
        }
        if (p == NULL) {
            cerr << "Error al abrir o crear ranking.dat para modificar." << endl;
            return false;
        }

        // Mueve el puntero a la posición deseada para actualizar
        fseek(p, sizeof(Ranking) * pos, SEEK_SET);

        // Escribe el registro en la posición y valida si se escribió correctamente
        bool escribio = (fwrite(this, sizeof(Ranking), 1, p) == 1);
        if (!escribio) {
            cerr << "Error al escribir en ranking.dat en la posición " << pos << endl;
        }

        fclose(p);
        return escribio;
    }


};

#endif // RANKING_H_INCLUDED

