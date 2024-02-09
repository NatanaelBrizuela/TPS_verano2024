#ifndef PRIMOS_H
#define PRIMOS_H
#include <string>

using namespace std;

const unsigned MAXIMO = 100000000;
const string PATH_PRIMOS = "primos.txt";

ofstream abrirArchivo();
void encontrarYguardarPrimos(ofstream &archivo);

#endif
// 9.92718