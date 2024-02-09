#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <string>
using namespace std;

const float DESCUENTO = 0.1;

class Producto
{
private:
    string nombre;
    float precio_unit;
    bool oferta;
    int cantidad;
    float precio_total;

public:
    /* CONSTRUCTOR CON PARAMETROS
     pre: -
     pos: Inicializa el objeto Producto con nombre, precio, oferta y cantidad.*/
    Producto(string nombre, float precio, bool oferta, int cantidad);

    /* CONSTRUCTOR DE COPIA
     pre: -
     pos: Inicializa una copia de un objeto*/
    Producto(const Producto &Prod);

    /*DEVUELVE EL NOMBRE
    Pre: El objeto debe estar correctamente instanciado.
    Pos: EL objeto devuelve el nombre del producto en forma de string. */
    string get_nombre();

    /*DEVUELVE EL PRECIO
    Pre: El objeto debe estar correctamente instanciado.
    Pos: El objeto devuelve el precio Unitario del produto en forma de flotante.*/
    float get_precios();

    /*DEVUELVE EL PRECIO UNITARIO DEL PRODUCTO
    Pre: El objeto debe estar correctamente instanciado.
    Pos: El objeto devuelve si este producto tiene alguna oferta en forma de booleano*/
    bool get_oferta();

    /*DEVUELVE LA CANTIDAD DE UNIDADES DEL PRODUCTO.
    Pre: El objeto debe estar correctamente instanciado.
    Pos: Devuelve la cantidad de elementos que tiene este producto en forma de entero. */
    float get_cantidad();

    /*DEVUELVE EL PRECIO TOTAL DEL PRODUCTO, APLICANDO LA OFERTA SI ESTA DISPONIBLE
    Pre: El objeto debe estar correctamente instanciado.
    Pos: Devuelve el precio total (precio unit * cantidad) y aplica la oferta asociada en foram de flotante*/
    float get_precio_total();

    /*MODIFICA LA CANTIDAD DE UNIDADES DEL PRODCUTO.
    Pre: El objeto debe estar correctamente instanciado.
    Pos: Se define una nueva cantidad de elementos del Producto en forma de entero. */
    void set_cantidad(int nuev_cantidad);
};
#endif