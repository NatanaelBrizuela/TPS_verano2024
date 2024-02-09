#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

// tipo de dato char
typedef int Dato;

class Nodo
{

private:
    Dato dato; // dato a almacenar
    Nodo* punt_sig;

public:
    // constructor con parametro
    Nodo(Dato dat);

    // destructor
    ~Nodo();

    // setea el dato (lo cambia)
    void asignar_dato(Dato dat);

    // obtener el dato
    Dato obtener_dato();

    // setear el puntero al siguiente nodo
    void asignar_siguiente_punt(Nodo* punt_sig);

    // obtener el puntero al nodo siguiente
    Nodo* obtener_siguiente_nodo();
};

#endif
