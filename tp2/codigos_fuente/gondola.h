#ifndef GONDOLA_H
#define GONDOLA_H
#include "Productos.h"

class Gondola
{
private:
    int capacidad;
    int cant_productos;
    Producto **productos_en_gondola;

public:
    /*CONSTRUCTOR CON PARAMETROS
     Pre: La capacidad debe ser un entero positivo.
     Pos: Crea el objeto Gondola con cero productos y un vector dinámico con una capacidad maxima.*/
    Gondola(int capacidad);

    /*CONSTRUCTOR DE COPIA*/
    Gondola(const Gondola &P);

    /*DESTRUCTOR*/
    ~Gondola();

    /*AGREGA PRODUCTOS A LA GONDOLA
    Pre:
        + nombre debe contener una cadena de caracteres válida que represente el nombre del producto.
        + precio debe ser un valor numérico positivo que represente el precio del producto.
        + oferta debe ser un valor booleano que indica si el producto tiene una oferta.
        + cantidad debe ser un valor entero positivo que represente la cantidad del producto a agregar.
        + La gondola debe tener espacio disponible para agregar el nuevo producto.
    pos:
        + Se agrega un nuevo producto a la gondola.
        + El nuevo producto se crea con los valores especificados en las variables `nombre`, `precio`, `oferta` y `cantidad`.
        + Si la gondola estaba llena, se duplica su capacidad.
        + El atributo `productos_en_gondola` de la gondola se actualiza para apuntar al nuevo vector de productos.
        + La cantidad de productos en la gondola se incrementa en 1.*/
    void agregar_producto_gondola(const string nombre, float precio, bool oferta, int cantidad);

    /*QUITAR PORDUCTOS DE LA GONDOLA
    Pre:
        + El índice debe ser menor que la cantidad de productos en la gondola.
    Pos:
        + Se elimina el producto en el índice especificado.
        + La cantidad de productos en la gondola se decrementa en 1
        + Si la cantidad de productos en la gondola es menor a la mitad de la capacidad, la capacidad se reduce a la mitad.*/
    void quitar_producto_gondola(int indice);

    /*SWAP
    pre:
        + El índice debe ser menor que la cantidad de productos en la gondola.
    pos:
        + Si el índice está dentro del rango válido, se intercambian el producto en el índice especificado con el último producto en la gondola.*/
    void swap(int indice);

    /* MUESTRA EL CONTENDIO DE LA GONDOLA
    Pre: -
    Pos:
        + Se muestra una lista de todos los productos en la gondola.*/
    void mostrar();

    /*DEVUELVE LA CANTIDAD DE PRODUCTOS EN LA GONDOLA*/
    int get_cant_productos();

    /*DEVUELE EL NOMBRE DEL PORDUCTO UBICADO EN LA POSICION 'INDICE' */
    string get_nombre_en_godnola(int indice);

    /*DEVUELVE EL NOMBRE DEL PRODUCTO UBICADO EN LA POSICION 'INDICE' */
    float get_precio_en_godnola(int indice);

    /*DEVUELVE SI EL PRODUCTO UBICADO EN LA POSICION 'INDICE' TIENE OFERTA*/
    bool get_oferta_en_gondola(int indice);

    /*DEVUELVE LA CANTIDAD DE ELEMENTOS DE UN PRODCUTO UBICADO EN LA POSICION 'INDICE'*/
    int get_cant_product_en_godnola(int indice);

    /*CAMBIA LA CANTIDAD DE ELEMNTOS DE UN PRODUCTO GUARDADO EN LA GONDOLA*/
    void set_cant_product_en_gondola(int nuevCantidad, int indice);
};

#endif
