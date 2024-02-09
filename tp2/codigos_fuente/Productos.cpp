#include <iostream>
#include "Productos.h"

Producto::Producto(const string nombre, float precio, bool oferta, int cantidad)
{
    this->nombre = nombre;
    this->precio_unit = precio;
    this->oferta = oferta;
    this->cantidad = cantidad;
    this->precio_total = (oferta) ? (precio * cantidad) - (precio * cantidad * DESCUENTO)
                                  : (precio * cantidad);
}

Producto::Producto(const Producto &Prod)
{
    this->nombre = Prod.nombre;
    this->precio_unit = Prod.precio_unit;
    this->oferta = Prod.oferta;
    this->cantidad = Prod.cantidad;
}

string Producto::get_nombre() { return nombre; }
float Producto::get_precios() { return precio_unit; }
bool Producto::get_oferta() { return oferta; }
float Producto::get_cantidad() { return cantidad; }
float Producto::get_precio_total() { return precio_total; }

void Producto::set_cantidad(int nuev_cantidad) { this->cantidad = nuev_cantidad; }
