#include "carrera.h"

// constructor
Carrera::Carrera(string nombre, int duracion, Lista_t<string> *materias)
{
    this->nombre = nombre;
    this->duracion = duracion;
    this->materias = materias;
}

// destructor
Carrera::~Carrera()
{
    // ?
}

// obtener nombre
string Carrera::obtener_nombre()
{
    return this->nombre;
}

// obtener duracion
int Carrera::obtener_duracion()
{
    return this->duracion;
}

// obtener materias
Lista_t<string> *Carrera::obtener_materias()
{
    return this->materias;
}

// mostrar materias de la carrera
void Carrera::mostrar_materias()
{
    cout << "--------------------" << endl
         << "materias de: " << this->nombre << endl
         << " - duracion: " << this->duracion << " años" << endl;

    this->materias->mostrar();
    cout << "--------------------" << endl;
}