#include "list_circular.h"

Lista_circular::Lista_circular()
{
    this->pn_inicio = nullptr;
    this->pn_final = nullptr;
    this->tamaño = 0;
}

Lista_circular::~Lista_circular()
{
    while (!lista_vacia())
    {
        this->eleimnar_dato_lista();
    }
}

bool Lista_circular::lista_vacia()
{
    return this->tamaño == 0;
}

bool Lista_circular::_indice_valido(int indice)
{
    return indice >= 0 && indice <= MAX_TAMAÑO;
}

int Lista_circular::obtener_tamaño()
{
    return this->tamaño;
}

Dato Lista_circular::obtener_dato_lista(const int indice)
{
    if (this->_indice_valido(indice))
    {

        Nodo *punt_aux = this->pn_inicio;
        int i = 1;
        while (i < indice)
        {
            punt_aux = punt_aux->obtener_siguiente_nodo();
            i++;
        }
        return punt_aux->obtener_dato();
    }
    else
    {
        cout << "Error. Indice invalido " << endl;
        return Dato();
    }
}

Nodo *Lista_circular::obtener_nodo(const int indice)
{

    Nodo *nodo_aux = this->pn_inicio;
    int i = 1;
    while (i < indice && nodo_aux != nullptr)
    {
        nodo_aux = nodo_aux->obtener_siguiente_nodo();
        i++;
    }
    return nodo_aux;
}

Dato Lista_circular::mas_antiguo()
{
    return pn_inicio->obtener_dato();
}

float Lista_circular::promedio()
{

    float suma = 0, promedio = 0;
    int i = 1;
    for (; i <= this->obtener_tamaño(); i++)
    {
        suma += this->obtener_dato_lista(i);
    }
    promedio = suma / (i - 1);
    return promedio;
}

void Lista_circular::insertar_lista(Dato dat)
{

    Nodo *nuevo_nodo = new Nodo(dat);

    if (this->lista_vacia())
    {
        this->pn_inicio = nuevo_nodo;
        this->pn_final = nuevo_nodo;

        tamaño++;
    }

    else
    {
        this->pn_final->asignar_siguiente_punt(nuevo_nodo);
        nuevo_nodo->asignar_siguiente_punt(pn_inicio);
        this->pn_final = nuevo_nodo;
        tamaño++;
        if (this->tamaño > MAX_TAMAÑO)
        {
            this->eleimnar_dato_lista();
        }
    }
}

void Lista_circular::eleimnar_dato_lista()
{
    if (!lista_vacia())
    {
        Nodo *nodo_borrar = this->pn_inicio;

        this->pn_inicio = nodo_borrar->obtener_siguiente_nodo();
        delete nodo_borrar;

        this->tamaño--;
    }
}
