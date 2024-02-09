#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

// tipo de dato char
template <class Dato>
class Nodo
{
private:
	Dato dato; // dato a almacenar
	Nodo *punt_sig;

public:
	// constructor con parametro
	Nodo(Dato dat);

	// destructor
	~Nodo();

	// obtener el dato
	Dato obtener_dato();

	// setea el dato (lo cambia)
	void asignar_dato(Dato dat);

	// setear el puntero al siguiente nodo
	void asignar_siguiente_punt(Nodo *sig_punt);

	// obtener el puntero al nodo siguiente
	Nodo *obtener_siguiente_nodo();
};

template <typename Dato>
Nodo<Dato>::Nodo(Dato dat)
{
	cout << "se construye el nodo" << this << endl;
	this->dato = dat;
	this->punt_sig = nullptr;
}

template <typename Dato>
Nodo<Dato>::~Nodo()
{
	cout << "se elimina nodo: " << this << endl;
}

template <typename Dato>
Dato Nodo<Dato>::obtener_dato()
{
	return this->dato;
}

template <typename Dato>
void Nodo<Dato>::asignar_dato(Dato dat)
{
	this->dato = dat;
}

template <typename Dato>
void Nodo<Dato>::asignar_siguiente_punt(Nodo *sig_punt)
{
	this->punt_sig = sig_punt;
}

template <typename Dato>
Nodo<Dato> *Nodo<Dato>::obtener_siguiente_nodo()
{
	return this->punt_sig;
}

#endif