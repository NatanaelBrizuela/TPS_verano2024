#include "busca_carreras.h"

Lista_t<Carrera *> *Buscador_Carreras::sugerir_carreras(Lista_t<Carrera *> *carreras,
                                                        int duracion_maxima,
                                                        Lista_t<string> *materias_predilectas)
{
    Lista_t<Carrera *> *lista_carreras_sugeridas = new Lista_t<Carrera *>;

    for (unsigned i = 1; i < carreras->obtener_tam(); i++)
    {
        Carrera *carrera_actual = carreras->obtener_dato_lista(i);
        Lista_t<string> *materias_actual = carrera_actual->obtener_materias();

        int coincidencias = 0;
        unsigned n = 1;
        while (n <= materias_actual->obtener_tam() && coincidencias < 3)
        {
            string materia_actual = materias_actual->obtener_dato_lista(n);
            unsigned m = 1;
            while (coincidencias <= 3 && m < materias_predilectas->obtener_tam())
            {
                string materia_predilecta = materias_predilectas->obtener_dato_lista(m);

                if (materia_actual == materia_predilecta)
                {
                    coincidencias++;
                }
                m++;
            }
            n++;
        }
        if (coincidencias >= 3 && carrera_actual->obtener_duracion() <= duracion_maxima)
        {
            lista_carreras_sugeridas->insertar_lista(carrera_actual, 1);
        }
    }
    return lista_carreras_sugeridas;
}
