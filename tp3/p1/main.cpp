#include "lista_se.h"

using namespace std;

int main()
{
    Lista_se lista_ordenada_1, lista_ordenada_2, lista_sin_orden;
    Lista_se *inteseccion_sin_orden, *inteseccion_con_orden;

    for (int i = 1; i < 10; i++)
    {
        lista_ordenada_1.insertar_lista(i, i);
        lista_ordenada_2.insertar_lista(i + 4, i);
    }
    lista_sin_orden.insertar_lista(9, 1);
    lista_sin_orden.insertar_lista(2, 2);
    lista_sin_orden.insertar_lista(4, 3);
    lista_sin_orden.insertar_lista(8, 2);
    lista_sin_orden.insertar_lista(5, 5);

    inteseccion_con_orden = lista_ordenada_1.interseccion_con_orden(lista_ordenada_2);
    inteseccion_sin_orden = lista_ordenada_1.interseccion_sin_orden(lista_sin_orden);

    cout << "lista sin orden: " << endl;
    while (!inteseccion_sin_orden->lista_vacia())
    {
        cout << inteseccion_sin_orden->obtener_dato_lista(1) << " ";
        inteseccion_sin_orden->eleimnar_dato_lista(1);
    }
    cout << endl;

    cout << "lista con orden: " << endl;
    while (!inteseccion_con_orden->lista_vacia())
    {
        cout << inteseccion_con_orden->obtener_dato_lista(1) << " ";
        inteseccion_con_orden->eleimnar_dato_lista(1);
    }
    cout << endl;

    delete inteseccion_sin_orden;
    delete inteseccion_con_orden;

    return 0;
}