#ifndef BUSCA_CARRERAS_H
#define BUSCA_CARRERAS_H

#include "carrera.h"

class Buscador_Carreras
{
private:
public:
    // Pre: - La lista de carreras no debe ser vacía.
    //      - La duración máxima debe ser mayor que cero.
    //      - La lista de materias predilectas no debe ser vacía.
    //      - Todos los elementos de la lista de carreras deben ser punteros a objetos de tipo Carrera.
    //      - Todos los elementos de la lista de materias predilectas deben ser cadenas de caracteres.
    //
    // Pos: - busca en “carreras” aquellas que tienen tres o más materias de
    //      - la lista “materias_predilectas” y una duración menor o igual que
    //      - duracion_maxima.
    //      - Devuelve un puntero a una lista con las carreras que cumplen con estas
    //      - características.
    Lista_t<Carrera *> *sugerir_carreras(Lista_t<Carrera *> *carreras,
                                         int duracion_maxima,
                                         Lista_t<string> *materias_predilectas);
};

#endif