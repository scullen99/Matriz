#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}



//Asignacion de matrices

Matriz& Matriz::operator= (const Matriz &m)
{
	if (matriz != NULL)
	{
		for (int i = 0; i < n_filas; i++)
			delete[] matriz[i];

		delete[] matriz;
		matriz = NULL;
	}

	this->n_filas = m.n_filas;
	this->n_columnas = m.n_columnas;
	this->matriz = NULL;
	if (n_filas > 0 && n_columnas > 0)
	{
		matriz = new double *[n_filas];

		for (int i = 0; i < n_filas; i++)
		{
			matriz[i] = new double[n_columnas];
			for (int j = 0; j < n_columnas; j++)
				matriz[i][j] = m.matriz[i][j];
		}
	}

	return(*this);
}


// Leer matriz
void Matriz::rellenarManual()
{
	double elemento;
	for (int i = 0; i < n_filas; i++)
	{
		cout << "Fila " << i << endl;
		for (int j = 0; j < n_columnas; j++)
		{
			cout << "Elemento " << j << endl;
			cin >> elemento;
			matriz[i][j] = elemento;
		}
		cout << endl;
	}

}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
	srand(seed);
	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			matriz[i][j] = rand();

}



// Imprimir Matriz
void Matriz::mostrarMatriz()
{
	for (int i = 0; i < n_filas; i++)
	{
		for (int j = 0; j < n_columnas; j++)
			cout << matriz[i][j] << " ";
		cout << endl;
	}
}

// Crear matriz por defecto
// 0 filas y 0 columnas
Matriz::Matriz()
{
	this->n_filas = 0;
	this->n_columnas = 0;

	matriz = NULL;

	//cout << "Matriz por defecto creada: " n_filas << n_columnas << endl;
}

// Crear matriz por parametro
Matriz::Matriz(int n_filas, int n_columnas)
{
	this->n_filas = n_filas;
	this->n_columnas = n_columnas;

	// Crear las filas
	matriz = new double *[n_filas];

	// Crear las columnas
	for (int i = 0; i < n_filas; i++)
		matriz[i] = new double[n_columnas];

	// Rellenar todas las casillas de la matriz por -1
	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			matriz[i][j] = -1;

	//cout << "Matriz por parametro creada: " n_filas << n_columnas << endl;
}

// Crear matriz por copia
Matriz::Matriz(const Matriz& a_copiar)
{
	n_filas = a_copiar.n_filas;
	n_columnas = a_copiar.n_columnas;

	// Crear las filas
	matriz = new double *[n_filas];

	// Crear las columnas
	for (int i = 0; i < n_filas; i++)
		matriz[i] = new double[n_columnas];

	for (int i = 0; i < a_copiar.n_filas; i++)
		for (int j = 0; j < a_copiar.n_columnas; j++)
			matriz[i][j] = a_copiar.matriz[i][j];

	//cout << "Matriz por copia creada: " n_filas << n_columnas << endl;
}

// Funcion productor escalar
Matriz Matriz::operator * (const int escalar)
{
	Matriz escalada(n_filas, n_columnas);

	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			escalada.matriz[i][j] = this->matriz[i][j] * escalar;

	return escalada;

	//cout << "Funcion producto escalar" << endl;
}

// Funcion maximo
double Matriz::obtenerMaximo()
{
	double maximo = matriz[0][0];

	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			if (matriz[i][j] > maximo)
				maximo = matriz[i][j];

	return maximo;
}

// Funcion minimo
double Matriz::obtenerMinimo()
{
	double minimo = matriz[0][0];

	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			if (matriz[i][j] < minimo)
				minimo = matriz[i][j];

	return minimo;
}

// Funcion simetrica
bool Matriz::esSimetrica()
{

	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			if (matriz[i][j] == matriz[j][i])
			{
				//cout << "Comprobando si es simetrica " << endl;
				// Solo es simetrica si todos los resultados son identicos
			}
			else
			{
				return false;
			}

	return true;
}

// Funcion traspuesta
Matriz Matriz::calcularTraspuesta()
{
	// Se intercambien el numero de filas y columnas
	Matriz temporal(n_columnas, n_filas);

	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
		{
			temporal.matriz[j][i] = matriz[i][j];
		}

	return temporal;

}

// Funcion suma
Matriz Matriz::operator + (const Matriz& matriz_B)
{
	assertdomjudge(this->n_filas == matriz_B.n_filas && this->n_columnas == matriz_B.n_columnas);
	// Estoy dando por hecho que la matriz A y B van a ser cuadradas siempre y del mismo tamanio,
	// por lo que el control de errores no esta definido
	// Se crea una tercera matriz, que sera la suma de la primera y la segunda matriz
	Matriz temporal_suma(n_filas, n_columnas);

	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			temporal_suma.matriz[i][j] = this->matriz[i][j] + matriz_B.matriz[i][j];
			// Matriz C = Matriz A + Matriz B 

	// cout << "Suma hecha " << endl;

	return temporal_suma;
}


// Funcion resta
Matriz Matriz::operator - (const Matriz& matriz_B)
{
	assertdomjudge(this->n_filas == matriz_B.n_filas && this->n_columnas == matriz_B.n_columnas);
	// Estoy dando por hecho que la matriz A y B van a ser cuadradas siempre y del mismo tamanio,
	// por lo que el control de errores no esta definido
	// Se crea una tercera matriz, que sera la resta de la primera y la segunda matriz
	Matriz temporal_resta(n_filas, n_columnas);

	for (int i = 0; i < n_filas; i++)
		for (int j = 0; j < n_columnas; j++)
			temporal_resta.matriz[i][j] = this->matriz[i][j] - matriz_B.matriz[i][j];
			// Matriz C = Matriz A - Matriz B 

	// cout << "Resta hecha " << endl;

	return temporal_resta;
}


// Destructor
Matriz::~Matriz()
{
	// Borra las columnas
	for (int i = 0; i < n_filas; i++)
	{
		delete[] matriz[i];
	}

	// Borra la fila que conserva la direccion de las columnas
	// recientemente eliminadas  
	delete matriz;
}