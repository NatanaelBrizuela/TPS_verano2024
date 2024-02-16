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
    // CONSTRUCTOR CON PARAMTEROS (nombre, duracion y lista de materias)
    // PRE: - El nombre de la carrera no debe ser vacío.
    //      - La duración de la carrera debe ser mayor que cero.
    //      - El puntero a la lista de materias no debe ser nulo.
    // POS: - Se crea una nueva instancia de la clase Carrera con los valores especificados.
    //      - El nombre de la carrera se establece correctamente.
    //      - La duración de la carrera se establece correctamente.
    //      - La lista de materias se establece correctamente.
    Carrera(string nombre, int duracion, Lista_t<string> *materias);

    // DESTRUCTOR
    ~Carrera();

    // DEVUELVE LA DURACION DE LA CARRERA
    // pre: -
    // pos: - Se devuelve la duración de la carrera.
    int obtener_duracion();

    // DEVUELVE EL NOMBRE DE LA CARRERA
    // pre: -
    // pos: - se devuelve el nombre de la carrera
    string obtener_nombre();

    // devuelve una lista de strings con materias
    // pre: -
    // pos: - Se devuelve un puntero a la lista de materias de la carrera.
    Lista_t<string> *obtener_materias();

    void mostrar_materias();
};
#endif