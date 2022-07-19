/****************************************************
* Henry Manuel Navarro                         		*
* C.I: 28.031.608                                   *
* ESTRUCTURA DE DATOS                               *
* SECCIÓN 01                                        *
* PRACTICA #1, Metodos de Ordenamiento				*
*****************************************************/

#include <iostream>
#include "Array/Array.hpp"
#include "Table/Table.hpp"

const int N1 = 200000; //Tamaño del Array
const int N2 = 1000; //Numero de elementos a ordenar en la segunda etapa

//Pausa el programa hasta que el usuario ingrese la tecla solicitada
void pausa(const char = '\n', const std::string = "\tPresione ENTER para continuar...");

int main()
{

	int array[N1]; //Array a ordenar
	int method = 0; //Contador de los metodos aplicados
	Table table; //Tabla encargada de los registros y mediciones de los tiempos de Ordenamiento

	//Llenamos el array de manera aleatoria, asegurandonos de que no hayan elementos repetidos
	randomFill(array,N1);

	std::cout << "\nPara un Array de " << N1 << " elementos.\n" << std::endl;
	pausa('\n',"\tPresione ENTER para comenzar a ordenar...");
	std::cout << "\nOrdenando por:\n" << std::endl;

	//Ordenamos y tomamos los tiempos para un Array Desordenado, Ordenado, Invertido
	table.takeTime(array,N1,method++,"Insercion",insertionSort);
	table.takeTime(array,N1,method++,"Seleccion",selectionSort);
	table.takeTime(array,N1,method++,"Burbuja ",bubbleSort);
	table.takeTime(array,N1,method++,"Burbuja Mej",improvedBubbleSort);
	table.takeTime(array,N1,method++,"ShellSort",shellSort);
	table.takeTime(array,N1,method++,"QuickSort",quickSort);

	//Mostramos los resultados Obtenidos
	table.print();

	//Mostramos los mejores tiempos para cada categoria (Desordenado, Ordenado, Invertido)
	std::cout << "\n    ---------Mejores Tiempos---------" << std::endl;
	table.betterTimes();

	//Repetimos el Proceso para los primero 1000 elementos del Array
	method = 0;

	std::cout << "\nPara los primeros " << N2 << " elementos de un Array.\n" << std::endl;
	pausa();
	std::cout << "\nOrdenando por:\n" << std::endl;

	//Ordenamos y tomamos los tiempos de cada metodo
	table.takeTime(array,N2,method++,"Insercion",insertionSort);
	table.takeTime(array,N2,method++,"Seleccion",selectionSort);
	table.takeTime(array,N2,method++,"Burbuja ",bubbleSort);
	table.takeTime(array,N2,method++,"Burbuja Mej",improvedBubbleSort);
	table.takeTime(array,N2,method++,"ShellSort",shellSort);
	table.takeTime(array,N2,method++,"QuickSort",quickSort);

	//Mostramos los resultados obtenidos
	table.print();

	//Mostramos los mejores tiempos para cada categoria
	std::cout << "\n    ---------Mejores Tiempos---------" << std::endl;
	table.betterTimes();

	return 0;
}

//Pausa el programa hasta que el usuario ingrese la tecla solicitada
void pausa(const char c, const std::string cad)
{
	std::cout << cad;
	while(getchar() != c);
}