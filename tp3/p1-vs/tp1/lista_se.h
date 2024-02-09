#ifndef LISTSA_SE_H
#define LISTA_SE_H

#include "nodo.h"

class Lista_se
{
private:
	// primer elemento de la lista
	Nodo* primero;

	// tamaño de la lista
	unsigned tamaño;

	// obtener el puntero al nodo siguiente
	// pre: 0 < pos <= cantidad
	// pos: devuelve un puntero al nodo en la posicion pos
	Nodo* obtener_nodo(unsigned indice);

public:
	// CONSTRUCTOR
	// pre: -
	// pos: construye una Lista
	Lista_se();

	// constructor de copia
	Lista_se(const Lista_se& lista);

	// destructor
	~Lista_se();

	// METODOS PUBLICOS

	// agregar un eleemnto a la lista
	void insertar_lista(Dato dat, unsigned indice);

	// pre: 0 < pos <= obtener_cantidad()
	// pos: elimina de la Lista el elemento en la posicion pos
	void eleimnar_dato_lista(unsigned indice);

	// lista vacia?
	// pre: -
	// pos: devuelve true si la Lista esta vacia
	// devuelve false en caso contrario
	bool lista_vacia();

	// obtener el dato que esta en la posicion indice
	// pre: 0 < pos <= obtener_cantidad()
	// pos: devuelve el elemento de la posicion pos
	Dato obtener_dato_lista(unsigned indice);

	// obtener el tamaño de la lista
	// pre: -
	// pos: devuelve la cantidad de elementos en la lista
	unsigned obtener_tamaño();

	// devuelve un puntero a una lista si que es la interseccion entre
	// la lista que invoca al metodo y la que se pasa por parametro
	// Lista_se *interseccion_sin_orden(Lista_se lista_2, Lista_se *lista3);
	// Lista_se *interseccion_con_orden(Lista_se lista_2, Lista_se *lista_3);

	// Si tu padrón es impar
	// Devuelve  un  puntero  a  una  lista  que  es  la  intersección  entre  la  lista  que  invoca  al
	// método y la que se pasa por parámetro.
	Lista_se* interseccion_sin_orden(Lista_se lista);

	Lista_se* interseccion_con_orden(Lista_se lista);

};

#endif