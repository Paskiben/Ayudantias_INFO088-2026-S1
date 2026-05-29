/*
	Problema: Se tiene una maleta que soporta 100 de peso, la cual se quiere llenar con objetos que tienen un peso determinado. 
	Se desea maximizar la cantidad de objetos en la maleta, sin exceder el peso máximo permitido.

	La mochila se representa por la siguiente estructura:

	struct Mochila {
		int pesoMaximo;
		vector<int> objetos;
	};

	Donde vector<int> objetos representa los pesos de los objetos agregados a la mochila.

	Solucion: Se debe utilizar un algoritmo para seleccionar los objetos que se pueden agregar a la mochila
	Esto se realizará utilizando una cola de prioridad para seleccionar los objetos con menor peso primero.
	Usted deberá completar las funciones:

	- llenarMochila(Mochila& mochila, priority_queue<int, vector<int>, greater<int>>& objetos);
		Se debe llenar la mochila con los objetos de menor peso hasta que no se pueda agregar más sin exceder el peso máximo.
	- crearColaDePrioridad(const vector<int>& pesos);
		Crea una cola de prioridad a partir de un vector de pesos, ordenando los objetos de menor a mayor peso.
	- crearObjetos(vector<int>& objetos, int n);
		Crea un vector de objetos con pesos aleatorios entre 1 y 50, donde n es la cantidad de objetos a crear.

	y el main para probar su funcionamiento.
	- Se debe llamar a las funciones codificadas
	- Se debe imprimir los objetos antes de llenar la mochila.
	- Se debe imprimir el contenido de la mochila al final del programa.

*/

#include <cstdio>
#include <vector>
#include <random>
#include <ctime>
#include <queue> 

struct Mochila
{
	int pesoMaximo;
	std::vector<int> objetos;
};

void llenarMochila(Mochila& mochila, std::priority_queue<int, std::vector<int>, std::greater<int>>& objetos);

std::priority_queue<int, std::vector<int>, std::greater<int>> crearColaDePrioridad(const std::vector<int>& pesos);

std::vector<int> crearObjetos(std::vector<int>& objetos, int n);

int main() {
	srand(time(NULL));
	Mochila mochila;
	mochila.pesoMaximo = 100;

	int n;
	printf("Ingrese la cantidad de objetos a crear: ");
	scanf("%d", &n);

	std::vector<int> objetos = crearObjetos(objetos, n);

	printf("Objetos disponibles (pesos):\n");
	for (int peso : objetos) {
		printf(" %d", peso);
	}
	printf("\n");

	auto colaDePrioridad = crearColaDePrioridad(objetos);

	llenarMochila(mochila, colaDePrioridad);

	printf("Mochila llena con peso máximo de %d\n", mochila.pesoMaximo);
	for (int peso : mochila.objetos) {
		printf(" %d", peso);
	}
	printf("\n");

	return 0;
}

void llenarMochila(Mochila& mochila, std::priority_queue<int, std::vector<int>, std::greater<int>>& objetos) {
	int pesoActual = 0;
	while (!objetos.empty()) {
		int pesoObjeto = objetos.top();
		if (pesoActual + pesoObjeto <= mochila.pesoMaximo) {
			mochila.objetos.push_back(pesoObjeto);
			pesoActual += pesoObjeto;
		}
		objetos.pop();
	}
}

std::priority_queue<int, std::vector<int>, std::greater<int>> crearColaDePrioridad(const std::vector<int>& pesos) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> cola;
	for (int peso : pesos) {
		cola.push(peso);
	}
	return cola;
}

std::vector<int> crearObjetos(std::vector<int>& objetos, int n) {
	std::vector<int> pesos;
	for (int i = 0; i < n; ++i) {
		int peso = rand() % 50 + 1; // Pesos entre 1 y 50
		pesos.push_back(peso);
	}
	return pesos;
}
