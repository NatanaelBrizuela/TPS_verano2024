#include <iostream>
#include <iomanip>
#include "gondola.h"
#include "Productos.h"

using namespace std;

Gondola::Gondola(int capacidad)
{
    this->capacidad = capacidad;
    this->cant_productos = 0;
    this->productos_en_gondola = new Producto *[capacidad];
}

Gondola::Gondola(const Gondola &otra_gondola)
{
    this->capacidad = otra_gondola.capacidad;
    this->cant_productos = otra_gondola.cant_productos;

    this->productos_en_gondola = new Producto *[capacidad];

    for (int i = 0; i < cant_productos; i++)
    {
        if (otra_gondola.productos_en_gondola[i] != nullptr)
        {
            this->productos_en_gondola[i] = new Producto(*(otra_gondola.productos_en_gondola[i]));
        }
        else
        {
            this->productos_en_gondola[i] = nullptr;
        }
    }
}

Gondola::~Gondola()
{
    for (int i = 0; i < cant_productos; i++)
    {
        delete productos_en_gondola[i];
    }
    delete[] productos_en_gondola;
}

void Gondola::agregar_producto_gondola(const string nombre, float precio, bool oferta, int cantidad)
{
    if (cant_productos >= capacidad)
    {
        Producto **nuevo_vector = new Producto *[capacidad * 2];
        cout << "* Gondola llena, se agrandara a " << capacidad * 2 << " espacios " << endl;

        for (int i = 0; i < capacidad; i++)
        {
            nuevo_vector[i] = productos_en_gondola[i];
        }

        delete[] productos_en_gondola;
        capacidad *= 2;
        productos_en_gondola = nuevo_vector;
    }

    productos_en_gondola[cant_productos++] = new Producto(nombre, precio, oferta, cantidad);
}

void Gondola::quitar_producto_gondola(int indice)
{
    swap(indice);

    delete productos_en_gondola[cant_productos - 1];
    cant_productos--;
    if (cant_productos < (capacidad / 2) + 1)
    {

        capacidad = (capacidad / 2) + 1;
        Producto **nuevo_vector = new Producto *[capacidad];
        for (int i = 0; i < capacidad; i++)
        {
            nuevo_vector[i] = productos_en_gondola[i];
        }

        delete[] productos_en_gondola;
        productos_en_gondola = nuevo_vector;
        cout << "/ la gondola tien " << cant_productos - 1
             << " Productos, Se redujo la gondola a " << capacidad - 1
             << " espacios. " << endl;
    }
}

void Gondola::swap(int indice)
{
    if (indice >= 0 && indice < cant_productos)
    {
        Producto *auxiliar = productos_en_gondola[indice];
        productos_en_gondola[indice] = productos_en_gondola[cant_productos - 1];
        productos_en_gondola[cant_productos - 1] = auxiliar;
    }
    else
    {
        cout << "Índice fuera de rango" << endl;
    }
}

void Gondola::mostrar()
{

    cout << endl
         << "________________________ PRODUCTOS EN GONDOLA ________________________" << endl;
    cout << setw(15) << "Nombre"
         << setw(11) << "Precio"
         << setw(7) << "Oferta"
         << setw(9) << "Cantidad" << endl;

    for (int i = 0; i < cant_productos; i++)
    {
        cout << setw(15) << productos_en_gondola[i]->get_nombre()
             << setw(10) << productos_en_gondola[i]->get_precios()
             << setw(6) << productos_en_gondola[i]->get_oferta()
             << setw(8) << productos_en_gondola[i]->get_cantidad() << endl;
    }
}

int Gondola::get_cant_productos() { return cant_productos; }
string Gondola::get_nombre_en_godnola(int i) { return productos_en_gondola[i]->get_nombre(); }
float Gondola::get_precio_en_godnola(int i) { return productos_en_gondola[i]->get_precios(); }
bool Gondola::get_oferta_en_gondola(int i) { return productos_en_gondola[i]->get_oferta(); }
int Gondola::get_cant_product_en_godnola(int i) { return productos_en_gondola[i]->get_cantidad(); }

void Gondola::set_cant_product_en_gondola(int indice, int nuevCantidad)
{
    productos_en_gondola[indice]->set_cantidad(nuevCantidad);
}