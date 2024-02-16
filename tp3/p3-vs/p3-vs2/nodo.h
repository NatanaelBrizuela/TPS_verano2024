#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

// Clase template Nodo
template <class Dato>
class Nodo
{
private:
    Dato dato; // dato a almacenar
    Nodo *punt_sig;

public:
    // CONSTRUCTOR CON PARAMTERO DATO
    // pre: -
    // pos: crea el nodo con el dato y un puntero a null
    Nodo(Dato dat);

    // DESTRUCTOR
    ~Nodo();

    // OBTENER EL DATO
    // devuelve el dato almacenado en el nodo
    Dato obtener_dato();

    // SETEA EL VALOR DE DATO
    // cambia el valor alamacenado en 'dato' por 'dat'
    void asignar_dato(Dato dat);

    // SETEA EL PUNTERO A OTRO NODO
    // cambia la posicion de memoria a la que apunta el atributo 'punt_sig'
    void asignar_siguiente_punt(Nodo *sig_punt);

    // DEVUELVE EL NODO AL QUE APUNTA 'punt_sig'
    Nodo *obtener_siguiente_nodo();
};

// constructor
template <typename Dato>
Nodo<Dato>::Nodo(Dato dat)
{
    this->dato = dat;
    this->punt_sig = nullptr;
}
// destructor
template <typename Dato>
Nodo<Dato>::~Nodo()
{
    // ?
}
// obtener dato
template <typename Dato>
Dato Nodo<Dato>::obtener_dato()
{
    return this->dato;
}
// asignar dato
template <typename Dato>
void Nodo<Dato>::asignar_dato(Dato dat)
{
    this->dato = dat;
}
// asignar_siguietne_punt
template <typename Dato>
void Nodo<Dato>::asignar_siguiente_punt(Nodo *sig_punt)
{
    this->punt_sig = sig_punt;
}
// obtener_siguiente_nodo
template <typename Dato>
Nodo<Dato> *Nodo<Dato>::obtener_siguiente_nodo()
{
    return this->punt_sig;
}

#endif