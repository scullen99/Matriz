#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
private:
	double **matriz;

	int n_filas;
	int n_columnas;

public:


	/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
		   Parámetro: la matriz que se va a asignar
		   Retorno: una nueva matriz con la matriz pasada como parámetro.
		   Precondicion: Ninguno.
		   Complejidad Temporal: O(n_filas*n_columnas)
		   Complejidad Espacial: O(n_filas*n_columnas)


	*/

	Matriz& operator= (const Matriz &m);


	/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario
		   Parámetro: Ninguno
		   Retorno: Ninguno
		   Precondicion: La matriz no debe estar vacía
		   Complejidad Temporal: O(n_filas*n_columnas)
		   Complejidad Espacial: O(1)


	*/

	void rellenarManual();


	/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria
		   Parámetro: semilla que se utiliza para el generador aleatorio
		   Retorno: Ninguno
		   Precondicion: La matriz no debe estar vacía
		   Complejidad Temporal: O(n_filas*n_columnas)
		   Complejidad Espacial: O(1)


	*/

	void rellenarAleatorio(long seed);



	/* Imprime por pantalla todos los elementos de la matriz del objeto actual
		   Parámetro: Ninguno
		   Retorno: Ninguno
		   Precondicion: La matriz no debe estar vacía
		   Complejidad Temporal: O(n_filas*n_columnas)
		   Complejidad Espacial: O(1)


	*/

	void mostrarMatriz();




	// Matriz por defecto
	Matriz();

	// Matriz por parametro
	Matriz(int, int);

	// Matriz por copia
	Matriz(const Matriz&);

	// Funcion producto escalar
	Matriz operator * (const int);

	// Funcion maximo
	double obtenerMaximo();

	// Funcion minimo
	double obtenerMinimo();

	// Funcion simetrica
	bool esSimetrica();

	// Funcion traspuesta
	Matriz calcularTraspuesta();

	// Funcion suma
	Matriz operator + (const Matriz&);

	// Funcion resta
	Matriz operator - (const Matriz&);

	// Destructor
	~Matriz();

};

#endif // MATRIZ_H
