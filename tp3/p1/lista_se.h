#ifndef LISTSA_SE_H
#define LISTA_SE_H

#include "nodo.h"

class Lista_se
{
private:
    // primer elemento de la lista
    Nodo *primero;

    // tamaño de la lista
    int tamaño;

    // obtener el puntero al nodo siguiente
    // pre: 0 < pos <= cantidad
    // pos: devuelve un puntero al nodo en la posicion pos
    Nodo *obtener_nodo(int indice);

public:
    // CONSTRUCTOR
    // pre: -
    // pos: construye una Lista
    Lista_se();

    // destructor
    ~Lista_se();

    // lista vacia?
    // pre: -
    // pos: devuelve true si la Lista esta vacia
    // devuelve false en caso contrario
    bool lista_vacia();

    // obtener el tamaño de la lista
    // pre: -
    // pos: devuelve la cantidad de elementos en la lista
    int obtener_tamaño();

    // agregar un eleemnto a la lista
    void insertar_lista(Dato dat, int indice);

    // pre: 0 < indice <= obtener_cantidad()
    // pos: elimina de la Lista el elemento en la posicion indice
    void eleimnar_dato_lista(int indice);

    // obtener el dato que esta en la posicion indice
    // pre: 0 < indice <= obtener_cantidad()
    // pos: devuelve el elemento de la posicion indice
    Dato obtener_dato_lista(int indice);

    // constructor de copia
    Lista_se(const Lista_se &lista);

    // pre: lista lista con elementos
    // pos// Post: La función devuelve una nueva lista que
    //   contiene la intersección (elementos comunes) de las dos listas.
    Lista_se *interseccion_sin_orden(Lista_se lista);

    // pre: las listas deben estar ordenas mayor a menor
    // Post: La función devuelve una nueva lista que contiene la
    //   intersección (elementos comunes) de las dos listas ordenadas.
    Lista_se *interseccion_con_orden(Lista_se lista);
};

#endif