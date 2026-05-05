#include "stack/Pila.h"

bool esPalindrome(const std::string &palabra);

int main(int argc, char** argv) {
	if (argc != 2){
		printf("Debe ejecutarse como ./program palabra\n");
		exit(EXIT_FAILURE);
	}
	std::string palabra = argv[1];

	if (esPalindrome(palabra))
		printf("La palabra es palindrome!!\n");
	else
		printf("La palabra NO es palindrome!!\n");

}

bool esPalindrome(const std::string &palabra) {
	//generamos la pila
	Pila miPila;
	int largo_palabra = static_cast<int>(palabra.length());
	bool is_odd = largo_palabra & 0b1;
	int mitad_palabra = largo_palabra / 2;
	int i = 0;
	while(i < mitad_palabra) {
		miPila.push(palabra[i]);
		++i;
	}
	if (is_odd) ++i;
	//comprobamos la palabra
	while(i < largo_palabra) {
		if (miPila.top() != palabra[i]){
			return false;
		}
		miPila.pop();
		++i;
	}
	if (miPila.isEmpty()) {
		return true;
	}
	return false;
}
