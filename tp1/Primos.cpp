#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include "Primos.h"
unsigned int tiempoInicial = clock();

using namespace std;

int main()
{

    ofstream archivo = abrirArchivo();

    encontrarYguardarPrimos(archivo);

    archivo.close();

    unsigned int tiempoFinal = clock();
    float tiempoTot = (float(tiempoFinal - tiempoInicial)) / CLOCKS_PER_SEC;

    cout << "el tiempo empleado es de: " << tiempoTot << "s." << endl;

    return 0;
}

ofstream abrirArchivo()
{
    ofstream archivo;
    archivo.open(PATH_PRIMOS, ios::out);

    return archivo;
}

void encontrarYguardarPrimos(ofstream &archivo)
{
    bool *vectPrimos = new bool[MAXIMO + 1];

    fill(vectPrimos, vectPrimos + MAXIMO + 1, true);

    vectPrimos[0] = false;
    vectPrimos[1] = false;

    for (int i = 2; i * i <= MAXIMO; ++i)
    {
        if (vectPrimos[i])
        {
            for (int j = i * i; j <= MAXIMO; j += i)
            {
                vectPrimos[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAXIMO; ++i)
    {
        if (vectPrimos[i])
        {
            archivo << i << endl;
        }
    }

    delete[] vectPrimos;
}