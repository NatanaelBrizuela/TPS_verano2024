#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "nodo_circ.h"

class Lista_circular
{
private:
    // primer elemento de la lista
    Nodo *pn_inicio;
    Nodo *pn_final;

    // tamaño de la lista
    int tamaño;

    // tamaño maximo
    const int MAX_TAMAÑO = 5;

    // tamaño minimo
    const int MIN_TAMAÑO = 2;

    // DEVUELVE EL NODO SIGUIENTE AL INDICADO
    // pre: 0 < pos <= cantidad
    // pos: devuelve un puntero al nodo en la posicion pos
    Nodo *obtener_nodo(int indice);

public:
    // CONSTRUCTOR
    // pre: -
    // pos: construye una Lista
    Lista_circular();

    // DESTRUCTOR
    ~Lista_circular();

    // METODOS PUBLICOS

    // LISTA VACIA?
    // pre: -
    // pos: devuelve true si la Lista esta vacia
    // devuelve false en caso contrario
    bool lista_vacia();

    // DEVUELVE EL TAMAÑO DE LA LISTA
    // pre: -
    // pos: devuelve la cantidad de elementos en la lista
    int obtener_tamaño();

    // DEVUELVE EL DATO INDICADO
    // pre: 0 < pos <= obtener_cantidad()
    // pos: devuelve el elemento de la posicion pos
    Dato obtener_dato_lista(int indice);

    // DEVUELVE EL PRIMERO DATO
    // pre: el nodo no debe estar vacio
    // pos: devuelve el primer dato ingresado
    Dato mas_antiguo();

    // PROMEDIO DE LOS DATOS EN LA LISTA
    // pre: los elemntos en la lista deben ser enteros
    // pos: recorre los elementos en la lista y devuelve su promedio
    float promedio();

    // INSERTAR LISTA
    // pre: lista correctamnte construida
    // pos: inserta un no
    void insertar_lista(Dato dat);

    // pre: 0 < pos <= obtener_cantidad()
    // pos: elimina de la Lista el elemento en la posicion pos
    void eleimnar_dato_lista();

    // pre: indice debe ser un entero
    // pos: devuelve si el indice esta entre los minimos y maximos perimtidos
    bool _indice_valido(int indice);
};
#endif