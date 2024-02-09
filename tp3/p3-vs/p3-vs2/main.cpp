#include "carrera.h"

using namespace std;

int main()
{
	Lista_t<string> materias_1;

	materias_1.insertar_lista("lecutra", 1);
	materias_1.insertar_lista("numeros creo", 2);

	Carrera contabili("contabilidad", 4, &materias_1);

	for (int i = 1; i <= contabili.obtener_materias()->obtener_tam(); i++)
	{
		cout << contabili.obtener_materias()->obtener_dato_lista(i) << endl;
	}

	return 0;
}