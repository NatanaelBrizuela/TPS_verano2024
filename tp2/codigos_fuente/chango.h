#ifndef CHANGO_H
#define CHANGO_H
#include <string>
#include "Productos.h"

using namespace std;

class Chango

{
private:
    int cantidad_en_chango;
    Producto **productos_chango;

public:
    /*CONSTRUCTOR CON PARAMETROS
     Pre: El parametro cantiad debe ser mayor o igual a cero
     Pos: Crea el objeto Chango con una cantidad de elementos y un vector dinamico nulo*/
    Chango(int cantidad_en_chango);

    /*AGREGA PRODUCTOS AL CHANGO
     Pre: Los parametros deben ser validos
     Pos: agrega un nuevo producto al vector de productos_chango*/
    void agrear_chango(string nombre, float precio, bool oferta, int cantidad);

    /*
    Pre: La clase chano debe haber sido correctamente inicializada
    Pos: Se muestra por pantalla una tabla con la siguiente información de los productos en el chango:
        +Nombre del producto
        +Precio unitario
        +Si está en oferta (S/N)
        +Cantidad
        +Precio total del producto/*/
    void mostrar();

    /*elimina la memoria dinamica solicitada.*/
    ~Chango();
};

#endif