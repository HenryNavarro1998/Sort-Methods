#ifndef Array_hpp
#define Array_hpp

//Librerias Incluidas
#include <iostream>
#include <ctime>
#include <cstdlib>

void randomFill(int*,const int); //Llena aleatoriamente el array recibido, se asegura que no hayan elementos repetidos
void copyArray(int*,const int*,const int); //Copia los valores de un array en otro
void invertArray(int*,const int); //Invierte el array recibido
void printArray(const int*,const int); //Muestra un arrray

//Metodos de Ordenamiento
void insertionSort(int*,const int); //Ordenamiento por Insercion
void selectionSort(int*,const int); //Ordenamiento por Seleccion
void bubbleSort(int*,const int); //Ordenamiento por Burbuja
void improvedBubbleSort(int*,const int); //Ordenamiento por Burbuja Mejorado
void shellSort(int*,const int); //Ordenamiento ShellSort
void quickSort(int*,int,int);
inline void quickSort(int* array, const int size){quickSort(array,0,size-1);};

//Busqueda Secuencial
bool sequientialSearch(const int*,const int,const int);

#endif