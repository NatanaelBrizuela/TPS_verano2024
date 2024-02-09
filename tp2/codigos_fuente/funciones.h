#ifndef MAIN_H
#define MAIN_H
#include "gondola.h"
#include "Productos.h"
#include "chango.h"
#include <string>

using namespace std;

const string PATH_PRODUCTOS = "./codigos_fuente/productos.txt";
const string PATH_COMPRA = "./codigos_fuente/compra.txt";

enum Modo_lectura
{
    Lectura = 1,
    Escritura = 2
};

/*Abre un archivo en modo lectura o escritura dependiendo del parametro elegido
PRE:
    'path' Debe ser una cadena de caracteres válida que represente la ruta al archivo.
    'modo' Debe ser un valor de tipo ModoLectura válido, ya sea Lectura o Escritura.
POS: devuelve un fstream.*/
fstream abrir_arch(string path, Modo_lectura modo);

/*Llena la gondola a partir de productos en arch_productos
PRE:
    'gondola_n' debe estar correctamente inicializada
    'arch_productos' debe ser un archivo abierto en modo escritura
POS: llena gondola_n de Productos*/
void llenar_gondola(Gondola &gondola_n, fstream &arch_productos);

/*Llena el chango de productos disponibles en la gondola
PRE:
    'gondola_n' debe estar correctamente inicializado y tener Productos
    'arch_compras' debe ser un archivo debidamente abierto en modo lectura.
    'chango_n' debe estar correctamente inicializado
POS: devuelve el chango con los productos solicitados*/
void llenar_chango(Chango &chango_n, fstream &arch_productos, Gondola &gondola_n);

/*En base al archivo compra, procesa si se puede comprar el producto y su cantidad
PRE:
    'chango_n' debe estar correctamente inicializado
    'gondola_n' debe estar correctamente inicializado y tener Productos
    'nombre_compra' es el nombre del Producto que se quiere comprar
    'cantidad_compra' es la cantidad de elementos del Producto que se quiere comprar
    'indice' es la ubicacion dentro de gondola_n del producto que se quiere comprar
POS: si encuentra el producto en la gondola, coloca la cantidad solicitada o la cantidad disponible del producto en chango_n.*/
void procesar_compra(Chango &chagno_n, string nombre_compra, int cantidad_compra, Gondola &gondola_n, int indice);

/*Actualiza la cantidad de elementos de un Producto dentro de la gondola
PRE:
    'indice' es la ubicacion del Prodcuto dentro de gondola_n
    'gondola_n' debe estar correctamente inicializado y tener Productos
    'cantidad_compra' es la cantidad de elementos que se desea comprar
PRE: los elementos de un producto se actualizan, si se queda en 0 o menos se elimina de gondola_n*/
void actualizar_cantidad_gondola(int incide, Gondola &gondola_n, int cantidad_compra);

/*actualiza el archivo de compras seguno lo que se coloco en el changuito
pre:
    'gondola_n' debe estar correctamente inicializado y tener Productos
pos: elimna el archivo de productos y crea uno nuevo con los valores actualizados de gondola_n*/
void actualizar_archivos(Gondola &gondola_n);

#endif