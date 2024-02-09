#include <iostream>
#include <iomanip>
#include <locale>
#include "chango.h"

using namespace std;

Chango::Chango(int cantidad_en_chango)
{
    this->cantidad_en_chango = cantidad_en_chango;
    this->productos_chango = nullptr;
}

void Chango::agrear_chango(string nombre, float precio, bool oferta, int cantidad)
{

    Producto **nuevo_vector_chango = new Producto *[cantidad_en_chango + 1];
    if (cantidad_en_chango != 0 && productos_chango != nullptr)
    {
        for (int i = 0; i < cantidad_en_chango; i++)
        {
            nuevo_vector_chango[i] = productos_chango[i];
        }
    }
    delete[] productos_chango;

    nuevo_vector_chango[cantidad_en_chango++] = new Producto(nombre, precio, oferta, cantidad);
    productos_chango = nuevo_vector_chango;
}
void Chango::mostrar()
{

    float total = 0;

    cout << endl
         << "________________________ PRODUCTOS EN CHANGO ________________________" << endl;
    cout
        << setw(17) << "Nombre "
        << setw(12) << "Precio "
        << setw(8) << "Oferta "
        << setw(10) << "Cantidad " << setw(16) << "Total "
        << endl;

    for (int i = 0; i < cantidad_en_chango; i++)
    {
        string oferta_S_N = (productos_chango[i]->get_oferta()) ? "S" : "N";

        cout << setw(16) << productos_chango[i]->get_nombre()
             << setw(11) << productos_chango[i]->get_precios()
             << setw(7) << oferta_S_N
             << setw(9) << productos_chango[i]->get_cantidad()
             << setw(16) << "$ " << productos_chango[i]->get_precio_total() << endl;

        total += productos_chango[i]->get_precio_total();
    }

    cout << endl
         << "_________ "
         << "Total: $" << total << endl;
}

Chango::~Chango()
{
    for (int i = 0; i < cantidad_en_chango; i++)
    {
        delete productos_chango[i];
    }
    delete[] productos_chango;
}
