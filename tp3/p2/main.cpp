#include "list_circular.h"

int main()
{
    Lista_circular lista_1, lista_2;

    lista_1.insertar_lista(1);
    lista_1.insertar_lista(2);
    lista_1.insertar_lista(3);
    lista_1.insertar_lista(4);
    lista_1.insertar_lista(33);
    lista_1.insertar_lista(6);
    lista_1.insertar_lista(7);

    cout << " Datos en la lista: " << endl;
    for (int i = 1; i <= lista_1.obtener_tamaño(); i++)
    {
        cout << "-> " << lista_1.obtener_dato_lista(i) << endl;
    }

    cout << "el mas antiguo es:" << lista_1.mas_antiguo() << endl;
    cout << "el pormedio es: " << lista_1.promedio() << endl;
    return 0;
}