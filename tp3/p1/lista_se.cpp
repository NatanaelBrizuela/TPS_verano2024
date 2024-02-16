#include "lista_se.h"

Lista_se::Lista_se()
{
    this->primero = nullptr;
    this->tamaño = 0;
}

Lista_se::~Lista_se()
{
    while (!lista_vacia())
    {
        this->eleimnar_dato_lista(1);
    }
}

bool Lista_se::lista_vacia()
{
    return this->primero == nullptr;
}

int Lista_se::obtener_tamaño()
{
    return tamaño;
}

void Lista_se::insertar_lista(Dato dat, int indice)
{
    Nodo *nuevo_nodo = new Nodo(dat);

    if (indice == 1)
    {
        nuevo_nodo->asignar_siguiente_punt(this->primero);
        this->primero = nuevo_nodo;
    }
    else
    {
        Nodo *anterior_nodo = obtener_nodo(indice - 1);

        nuevo_nodo->asignar_siguiente_punt(anterior_nodo->obtener_siguiente_nodo());
        anterior_nodo->asignar_siguiente_punt(nuevo_nodo);
    }
    this->tamaño++;
}

void Lista_se::eleimnar_dato_lista(const int indice)
{
    Nodo *nodo_borrar = this->primero;

    if (indice == 1)
    {
        this->primero = nodo_borrar->obtener_siguiente_nodo();
    }
    else
    {
        Nodo *nodo_anterior = obtener_nodo(indice - 1);
        nodo_borrar = nodo_anterior->obtener_siguiente_nodo();
        nodo_anterior->asignar_siguiente_punt(nodo_borrar->obtener_siguiente_nodo());
    }
    delete nodo_borrar;
    this->tamaño--;
}

Nodo *Lista_se::obtener_nodo(const int indice)
{
    Nodo *nodo_auxiliar = this->primero;
    unsigned i = 1;
    while (i < indice && nodo_auxiliar != nullptr)
    {
        nodo_auxiliar = nodo_auxiliar->obtener_siguiente_nodo();
        i++;
    }
    return nodo_auxiliar;
}

Dato Lista_se::obtener_dato_lista(const int indice)
{
    Nodo *punt_aux = obtener_nodo(indice);
    return punt_aux->obtener_dato();
}

Lista_se::Lista_se(const Lista_se &lista)
{
    this->tamaño = lista.tamaño;

    if (lista.primero == nullptr)
    {
        this->primero = nullptr;
        return;
    }

    // Crear un nuevo nodo para el primer elemento de la nueva lista
    Nodo *nuevo_nodo = new Nodo(lista.primero->obtener_dato());
    this->primero = nuevo_nodo;

    Nodo *actual_original = lista.primero->obtener_siguiente_nodo();
    Nodo *actual_nuevo = this->primero;

    while (actual_original != nullptr)
    {
        Nodo *nuevo_nodo = new Nodo(actual_original->obtener_dato());
        actual_nuevo->asignar_siguiente_punt(nuevo_nodo);
        actual_nuevo = actual_nuevo->obtener_siguiente_nodo();
        actual_original = actual_original->obtener_siguiente_nodo();
    }
    actual_nuevo->asignar_siguiente_punt(nullptr);
}

Lista_se *Lista_se::interseccion_sin_orden(Lista_se lista)
{
    Lista_se *lista_interseccion = new Lista_se();
    Nodo *nodo_actual = this->primero;

    while (nodo_actual != nullptr)
    {
        Nodo *nodo_buscador = lista.primero;

        while (nodo_buscador != nullptr)
        {
            if (nodo_actual->obtener_dato() == nodo_buscador->obtener_dato())
            {
                lista_interseccion->insertar_lista(nodo_actual->obtener_dato(), lista_interseccion->obtener_tamaño() + 1);
            }
            nodo_buscador = nodo_buscador->obtener_siguiente_nodo();
        }
        nodo_actual = nodo_actual->obtener_siguiente_nodo();
    }
    return lista_interseccion;
}

Lista_se *Lista_se::interseccion_con_orden(Lista_se lista)
{
    Lista_se *lista_interseccion = new Lista_se();
    Nodo *nodo_actual_1 = this->primero;
    Nodo *nodo_actual_2 = lista.primero;

    while (nodo_actual_1 != nullptr && nodo_actual_2 != nullptr)
    {
        if (nodo_actual_1->obtener_dato() < nodo_actual_2->obtener_dato())
        {
            // Avanzar el cursor en L1
            nodo_actual_1 = nodo_actual_1->obtener_siguiente_nodo();
        }
        else if (nodo_actual_1->obtener_dato() > nodo_actual_2->obtener_dato())
        {
            // Avanzar el cursor en L2
            nodo_actual_2 = nodo_actual_2->obtener_siguiente_nodo();
        }
        else
        {
            // Elementos iguales: agregar a la lista de intersección y avanzar ambos cursores
            lista_interseccion->insertar_lista(nodo_actual_1->obtener_dato(), lista_interseccion->obtener_tamaño() + 1);
            nodo_actual_1 = nodo_actual_1->obtener_siguiente_nodo();
            nodo_actual_2 = nodo_actual_2->obtener_siguiente_nodo();
        }
    }

    return lista_interseccion;
}
