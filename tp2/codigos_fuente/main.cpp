#include <iostream>
#include <fstream>

#include "funciones.h"
using namespace std;

int main()
{
    fstream arch_productos = abrir_arch(PATH_PRODUCTOS, Lectura);
    fstream arch_compras = abrir_arch(PATH_COMPRA, Lectura);

    Gondola gondola_n(5);
    Chango chango_n(0);

    llenar_gondola(gondola_n, arch_productos);
    llenar_chango(chango_n, arch_compras, gondola_n);

    chango_n.mostrar();

    arch_productos.close();
    arch_compras.close();

    actualizar_archivos(gondola_n);
    return 0;
}
