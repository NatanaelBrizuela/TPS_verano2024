#include "lista_se.h"

using namespace std;

int main()
{
    Lista_se listita, lista2;
    Lista_se* lista_inter_sin,*lista_inter_ord;

    listita.insertar_lista(1, 1);
    listita.insertar_lista(3, 2);
    listita.insertar_lista(5, 3);
    listita.insertar_lista(7, 4);
    listita.insertar_lista(8, 5);
    listita.insertar_lista(10, 6);
    listita.insertar_lista(11, 7);
    listita.insertar_lista(12, 8);

    lista2.insertar_lista(3, 1);
    lista2.insertar_lista(4, 2);
    lista2.insertar_lista(5, 3);
    lista2.insertar_lista(6, 4);
    lista2.insertar_lista(7, 5);
    lista2.insertar_lista(8, 6);
    lista2.insertar_lista(9, 7);
    lista2.insertar_lista(12, 8);

    lista_inter_sin = listita.interseccion_sin_orden(lista2);
    lista_inter_ord = listita.interseccion_con_orden(lista2);

    while (!lista_inter_sin->lista_vacia())
    {
        cout << lista_inter_sin->obtener_dato_lista(1) << " ";
        lista_inter_sin->eleimnar_dato_lista(1);
    }
    cout << endl;
    while (!lista_inter_ord->lista_vacia())
    {
        cout << lista_inter_ord->obtener_dato_lista(1) << " ";
        lista_inter_ord->eleimnar_dato_lista(1);
    }
    cout << endl;

    //delete lista_inter_sin;
    delete lista_inter_ord;

    return 0;
}