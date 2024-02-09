#include "carrera.h"

Carrera::Carrera(string nombre, int duracion, Lista_t<string> *materias)
{
    this->nombre = nombre;
    this->duracion = duracion;
    this->materias = materias;
}

Carrera::~Carrera()
{
    cout << "se elimino una carrera: " << this->nombre;
}

string Carrera::obtener_nombre()
{
    return this->nombre;
}

int Carrera::obtener_duracion()
{
    return this->duracion;
}

Lista_t<string> *Carrera::obtener_materias()
{
    return this->materias;
}
