#include "nodo.h"

// constructor
Nodo::Nodo(Dato dat)
{
    // cout << "se construye el nodo" << this << endl;
    this->dato = dat;
    this->punt_sig = nullptr;
}

// destructor
Nodo::~Nodo()
{
    // cout << "se destruye el nodo " << this << endl;
}

// cambiar el dato
void Nodo::asignar_dato(Dato dat)
{
    this->dato = dat;
}

// obttiene el dato
Dato Nodo::obtener_dato()
{
    return this->dato;
}
// cambia el puntero
void Nodo::asignar_siguiente_punt(Nodo *sig_punt)
{
    this->punt_sig = sig_punt;
}

// obtiene el puntero
Nodo *Nodo::obtener_siguiente_nodo()
{
    return this->punt_sig;
}
