#ifndef _LISTA_T_H
#define _LISTA_T_H
#include "nodo.h"

template <typename Dato>
class Lista_t
{
private:
	Nodo<Dato> *primer_punt;

	unsigned tam;

	Nodo<Dato> *obtener_nodo(unsigned indice);

public:
	Lista_t();

	Lista_t(const Lista_t &lista);

	~Lista_t();

	void insertar_lista(Dato dat, unsigned indice);

	void eleimnar_dato_lista(unsigned indice);

	unsigned obtener_tam();

	bool lista_vacia();

	Dato obtener_dato_lista(unsigned indice);
};

// Construcotr sin parametros
template <typename Dato>
Lista_t<Dato>::Lista_t()
{
	// cout << "se construye el nodo" << this << endl;
	this->primer_punt = nullptr;
	this->tam = 0;
};

// lista vacia?
template <typename Dato>
bool Lista_t<Dato>::lista_vacia()
{
	return this->primer_punt == nullptr;
}

// devuelve el tama�o de la lista
template <typename Dato>
unsigned Lista_t<Dato>::obtener_tam()
{
	return this->tam;
}

// devuelve el nodo ubicado en el indice
template <typename Dato>
Nodo<Dato> *Lista_t<Dato>::obtener_nodo(const unsigned indice)
{
	Nodo<Dato> *nodo_auxiliar = this->primer_punt;
	unsigned i = 1;
	while (i < indice && nodo_auxiliar != nullptr)
	{
		nodo_auxiliar = nodo_auxiliar->obtener_siguiente_nodo();
		i++;
	}
	return nodo_auxiliar;
}

// Inserta un dato en un indice
template <typename Dato>
void Lista_t<Dato>::insertar_lista(Dato dat, unsigned indice)
{
	Nodo<Dato> *nuevo_nodo = new Nodo<Dato>(dat);

	if (indice == 1)
	{
		nuevo_nodo->asignar_siguiente_punt(this->primer_punt);
		this->primer_punt = nuevo_nodo;
	}
	else
	{
		Nodo<Dato> *anterior_nodo = obtener_nodo(indice - 1);

		nuevo_nodo->asignar_siguiente_punt(anterior_nodo->obtener_siguiente_nodo());
		anterior_nodo->asignar_siguiente_punt(nuevo_nodo);
	}
	this->tam++;
}

// elina el dato en la ubicacion indice
template <typename Dato>
void Lista_t<Dato>::eleimnar_dato_lista(unsigned indice)
{
	Nodo<Dato> *nodo_borrar = this->primer_punt;

	if (indice == 1)
	{
		this->primer_punt = nodo_borrar->obtener_siguiente_nodo();
	}
	else
	{
		Nodo<Dato> *nodo_anterior = obtener_nodo(indice - 1);
		nodo_borrar = nodo_anterior->obtener_siguiente_nodo();
		nodo_anterior->asignar_siguiente_punt(nodo_borrar->obtener_siguiente_nodo());
	}
	delete nodo_borrar;
	this->tam--;
}

// devuelve el tama�o de la lista
template <typename Dato>
Dato Lista_t<Dato>::obtener_dato_lista(const unsigned indice)
{
	Nodo<Dato> *punt_aux = obtener_nodo(indice);
	return punt_aux->obtener_dato();
}

// constructo de copia
template <typename Dato>
Lista_t<Dato>::Lista_t(const Lista_t &lista)
{
	this->tam = lista.tam;

	if (lista.primer_punt == nullptr)
	{
		this->primer_punt = nullptr;
		return;
	}

	// Crear un nuevo nodo para el primer elemento de la nueva lista
	Nodo<Dato> *nuevo_nodo = new Nodo<Dato>(lista.primer_punt->obtener_dato());
	this->primer_punt = nuevo_nodo;

	Nodo<Dato> *actual_original = lista.primer_punt->obtener_siguiente_nodo();
	Nodo<Dato> *actual_nuevo = this->primer_punt;

	while (actual_original != nullptr)
	{
		Nodo<Dato> *nuevo_nodo = new Nodo<Dato>(actual_original->obtener_dato());
		actual_nuevo->asignar_siguiente_punt(nuevo_nodo);
		actual_nuevo = actual_nuevo->obtener_siguiente_nodo();
		actual_original = actual_original->obtener_siguiente_nodo();
	}
	actual_nuevo->asignar_siguiente_punt(nullptr);
}

// Destructor
template <typename Dato>
Lista_t<Dato>::~Lista_t()
{
	while (!lista_vacia())
	{
		this->eleimnar_dato_lista(1);
	}
}

#endif
// Ejemplo de uso de la plantilla
// Nodo<int> nodoEntero; // Ejemplo con tipo de dato int
// Nodo<double> nodoDecimal; // Ejemplo con tipo de dato double