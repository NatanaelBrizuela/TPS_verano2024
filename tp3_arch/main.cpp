#include "lista_t.h"

using namespace std;

int main()
{
	Lista_t<string> lista_ordenada_1;


	lista_ordenada_1.insertar_lista("hol2", 1);
	lista_ordenada_1.insertar_lista("holi", 2);

	for (int i = 1; i <= lista_ordenada_1.obtener_tam(); i++) {
		cout << lista_ordenada_1.obtener_dato_lista(i) << endl;
	}


	return 0;
}