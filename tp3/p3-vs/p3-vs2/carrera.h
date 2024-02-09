#ifndef CARRERA_NODO_H
#define CARRERA_NODO_H
#include "lista_t.h"

class Carrera
{
private:
    string nombre;
    int duracion;

    Lista_t<string> *materias;

public:
    /* Crea una Carrera con su nombre, la duración (en años) y una lista
    de materias */
    Carrera(string nombre, int duracion, Lista_t<string> *materias);
    // destructor
    ~Carrera();
    // devuelve la duracion de la carrera en años
    int obtener_duracion();
    string obtener_nombre();
    Lista_t<string> *obtener_materias();
};
#endif