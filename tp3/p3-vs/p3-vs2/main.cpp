#include "busca_carreras.h"

using namespace std;

int main()
{
    Lista_t<string> *m_contabilidad = new Lista_t<string>();
    Lista_t<string> *m_sociologia = new Lista_t<string>();
    Lista_t<string> *m_predilectas = new Lista_t<string>();

    m_predilectas->insertar_lista("Lengua Castellana y Literatura", 1);
    m_predilectas->insertar_lista("Artes Visuales", 2);
    m_predilectas->insertar_lista("Matemáticas", 3);
    m_predilectas->insertar_lista("Introducción a la Economía", 3);
    m_predilectas->insertar_lista("Introducción a la Psicología", 3);

    m_contabilidad->insertar_lista("Introducción a la Psicología", 1);
    m_contabilidad->insertar_lista("Introducción a la Economía", 1);
    m_contabilidad->insertar_lista("Lengua Castellana y Literatura", 1);
    m_contabilidad->insertar_lista("Filosofía", 2);
    m_contabilidad->insertar_lista("Matemáticas", 3);

    m_sociologia->insertar_lista("Lengua Castellana y Literatura", 1);
    m_sociologia->insertar_lista("Física", 2);
    m_sociologia->insertar_lista("Teoría Sociológica", 2);
    m_sociologia->insertar_lista("Métodos de Investigación Social", 4);
    m_sociologia->insertar_lista("Estadística Social", 5);
    m_sociologia->insertar_lista("Sociología de la Desigualdad", 6);
    m_sociologia->insertar_lista("Derecho", 4);

    Carrera *contabilidad = new Carrera("contabilidad", 4, m_contabilidad);
    Carrera *sociologia = new Carrera("sociologia", 5, m_sociologia);

    cout << "materias predilectas: " << endl;
    m_predilectas->mostrar();

    cout << "Carreras disponibles : " << endl;
    contabilidad->mostrar_materias();
    sociologia->mostrar_materias();

    Lista_t<Carrera *> *facultad = new Lista_t<Carrera *>();

    facultad->insertar_lista(contabilidad, 1);
    facultad->insertar_lista(sociologia, 2);

    Buscador_Carreras buscador;
    Lista_t<Carrera *> *sugeridas = buscador.sugerir_carreras(facultad, 5, m_predilectas);

    cout << "Carreras sugeridas : " << endl;
    for (int n = 1; n <= sugeridas->obtener_tam(); n++)
    {
        Carrera *carrera_actual = sugeridas->obtener_dato_lista(n);

        cout << " -> " << carrera_actual->obtener_nombre() << endl;
    }

    delete m_contabilidad;
    delete m_sociologia;
    delete m_predilectas;
    delete contabilidad;
    delete sociologia;
    delete facultad;
    delete sugeridas;

    return 0;
}
