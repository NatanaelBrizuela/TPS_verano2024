#ifndef _LISTA_T_H
#define _LISTA_T_H
#include "nodo.h"

// clase template Lista_t
template <typename Dato>
class Lista_t
{
private:
    Nodo<Dato> *primer_punt; // puntero al pirmer nodo

    int tam;

public:
    // CONSTRUCTOR SIN PARAMETROS
    // pre: -
    // pos: - Se crea una lista vacía.
    //      - El puntero primer_punt se establece a nullptr.
    //      - El tamaño de la lista se establece a 0.
    Lista_t();

    // DESTRUCTOR
    ~Lista_t();

    // **Funciones de acceso:**

    // Lista vacía?
    // pre: -
    // pos: - La función devuelve 'true' si la lista está vacía y 'false' en caso contrario
    bool lista_vacia() const;

    // Devuelve el tamaño de la lista
    // pre: -
    // pos: devuelve el tamaño de la lista
    int obtener_tam() const;

    // **Funciones de modificación:**

    // INSERTAR UN DATO EN LA LISTA
    // pre: - El índice indice debe ser mayor o igual que 1
    //        y menor o igual que el tamaño actual de la lista más 1.
    // pos: - Se  inserta un nuevo nodo con el dato especificado en
    //        la posición indicada por el índice.
    //      - El tamaño de la lista se  incrementa en 1.
    void insertar_lista(Dato dat, int indice);

    // ELINA UN DATO DE LA LISTA
    // pre: - El índice indice debe ser mayor o igual que 1 y menor o igual
    //        que el tamaño actual de la lista.
    // pos: - Se elimina el nodo en la posición indicada por el índice.
    //      - El tamaño de la lista se ha decrementado en 1.
    void eleimnar_dato_lista(int indice);

    // **Funciones de consulta:**

    // DEVUELVE EL DATO INDICADO
    // pre: - El índice indice debe ser mayor o igual que 1
    //        y menor o igual que el tamaño actual de la lista
    // pos: - Se devuelve el dato almacenado en el nodo en la posición indicada por el índice.
    Dato obtener_dato_lista(int indice) const;

    // MUESTRA EL CONTENIDO DE LA LISTA
    // pre: -
    // pos: - recorre la lista y devuelve lo que contiene el dato de sus nodos
    void mostrar();

private:
    // **Funciones auxiliares:**

    // Devuelve el nodo ubicado en el índice
    // pre: - El índice indice debe ser mayor o igual que 1 y menor o igual que el tamaño actual de la lista.
    // pos: - Se devuelve un puntero al nodo en la posición indicada por el índice.
    //      - Si el índice no es válido, se devuelve un puntero nulo.
    Nodo<Dato> *obtener_nodo(const int indice) const;
};

// mostrar
template <typename Dato>
void Lista_t<Dato>::mostrar()
{

    for (int i = 1; i <= this->tam; i++)
    {
        cout << " - " << this->obtener_dato_lista(i) << endl;
        }
}

// constructor
template <typename Dato>
Lista_t<Dato>::Lista_t()
{
    this->primer_punt = nullptr;
    this->tam = 0;
}

// destructor
template <typename Dato>
Lista_t<Dato>::~Lista_t()
{
    while (!lista_vacia())
    {
        this->eleimnar_dato_lista(1);
    }
}

// lista vacia?
template <typename Dato>
bool Lista_t<Dato>::lista_vacia() const
{
    return this->primer_punt == nullptr;
}

// obtener tamaño
template <typename Dato>
int Lista_t<Dato>::obtener_tam() const
{
    return this->tam;
}

// inserta a la lista
template <typename Dato>
void Lista_t<Dato>::insertar_lista(Dato dat, int indice)
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

// elimnar un dato de la lista
template <typename Dato>
void Lista_t<Dato>::eleimnar_dato_lista(int indice)
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

// obtener dato de la lista
template <typename Dato>
Dato Lista_t<Dato>::obtener_dato_lista(int indice) const
{
    Nodo<Dato> *punt_aux = obtener_nodo(indice);
    return punt_aux->obtener_dato();
}

// obtener nodo
template <typename Dato>
Nodo<Dato> *Lista_t<Dato>::obtener_nodo(const int indice) const
{
    Nodo<Dato> *nodo_auxiliar = this->primer_punt;
    int i = 1;
    while (i < indice && nodo_auxiliar != nullptr)
    {
        nodo_auxiliar = nodo_auxiliar->obtener_siguiente_nodo();
        i++;
    }
    return nodo_auxiliar;
}

#endif
