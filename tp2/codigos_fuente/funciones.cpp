#include "funciones.h"
#include <iostream>
#include <fstream>

using namespace std;

fstream abrir_arch(string path, Modo_lectura modo)
{
    ios_base::openmode modoApertura;

    if (modo == Modo_lectura::Lectura)
    {
        modoApertura = ios::in;
    }
    else if (modo == Modo_lectura::Escritura)
    {
        modoApertura = ios::out | ios::trunc;
    }

    fstream archivo(path, modoApertura);

    if (!archivo.is_open())
    {
        cout << "no se pudo abrir el arhcivo:" << path << endl;
        exit(EXIT_FAILURE);
    }
    return archivo;
}

void llenar_gondola(Gondola &gondola_n, fstream &arch_productos)
{
    string nombre;
    float precio;
    bool oferta;
    int cantidad;

    while (arch_productos >> nombre >> precio >> oferta >> cantidad)
    {
        gondola_n.agregar_producto_gondola(nombre, precio, oferta, cantidad);
    }
}

void llenar_chango(Chango &chango_n, fstream &arch_compras, Gondola &gondola_n)
{
    string nombre_compra;
    int cantidad_compra;
    while (arch_compras >> nombre_compra >> cantidad_compra)
    {
        bool se_encontro = false;
        int i = 0;
        while (!se_encontro && i < gondola_n.get_cant_productos())
        {
            if (gondola_n.get_nombre_en_godnola(i) == nombre_compra)
            {
                procesar_compra(chango_n, nombre_compra, cantidad_compra, gondola_n, i);
                actualizar_cantidad_gondola(i, gondola_n, cantidad_compra);
                se_encontro = true;
            }
            i++;
        }
        if (!se_encontro)
        {
            cout << "- No se encontro el producto [" << nombre_compra << "]" << endl;
        }
    }
}

void procesar_compra(Chango &chango_n, string nombre_compra, int cantidad_compra, Gondola &gondola_n, int indice)
{
    float precio = gondola_n.get_precio_en_godnola(indice);
    bool oferta = gondola_n.get_oferta_en_gondola(indice);
    int cantidad_gondola = gondola_n.get_cant_product_en_godnola(indice);

    if (cantidad_compra > cantidad_gondola)
    {
        cout << "+ No hay " << cantidad_compra
             << " productos de [" << nombre_compra
             << "] en la gondola, se agregaran solo: " << cantidad_gondola << endl;
        cantidad_compra = cantidad_gondola;
    }
    chango_n.agrear_chango(nombre_compra, precio, oferta, cantidad_compra);
}

void actualizar_cantidad_gondola(int indice, Gondola &gondola_n, int cantidad_compra)
{
    int nuev_cant_gondola = gondola_n.get_cant_product_en_godnola(indice) - cantidad_compra;

    if (nuev_cant_gondola <= 0)
    {

        gondola_n.quitar_producto_gondola(indice);
    }
    else
    {
        gondola_n.set_cant_product_en_gondola(indice, nuev_cant_gondola);
    }
}

void actualizar_archivos(Gondola &godnola_n)
{

    fstream n_ach_productos = abrir_arch(PATH_PRODUCTOS, Escritura);

    for (int i = 0; i < godnola_n.get_cant_productos(); i++)
    {
        n_ach_productos << godnola_n.get_nombre_en_godnola(i) << "\t"
                        << godnola_n.get_precio_en_godnola(i) << "\t"
                        << godnola_n.get_oferta_en_gondola(i) << "\t"
                        << godnola_n.get_cant_product_en_godnola(i) << endl;
    }

    n_ach_productos.close();
}