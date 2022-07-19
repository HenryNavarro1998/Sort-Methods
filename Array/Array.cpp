#include "Array.hpp"

//Intercambia 2 elementos del Array
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

//Llena aleatoriamente el array recibido, se asegura que no hayan elementos repetidos
void randomFill(int* array, const int size)
{
	//Inicializamos una semilla para generar valores aleatorios
	srand(time(NULL));
	for(int i = 0; i < size; i++)
	{
		int num;

		//Generamos valores aleatorios, hasta que el valor generado no exista en el array
		do num = (rand() * rand()) % 1000000; while(sequientialSearch(array,size,num));

		//Registramos el valor y mostramos el progreso del llenado
		array[i] = num;
		std::cout << "Llenando: [" << i+1 << "/" << size << "]" << ((i == size-1)? "\n" : "\r");
	}
}

//Copia los valores de un array en otro
void copyArray(int* array1, const int* array2, const int size)
{
	for (int i = 0; i < size; i++)
		array1[i] = array2[i];
}

//Invierte el array recibido
void invertArray(int* array, const int size)
{
	for(int i = 0; i < size/2; i++)
		swap(array[i],array[size-(1+i)]);
}

//Muestra un arrray
void printArray(const int* array, const int size)
{
	for(int i = 0; i < size; i++)
		std::cout << "[" << array[i] << "]";
	std::cout << std::endl;
}

//-----------------------Metodos de Ordenamiento-------------------------------//

//Ordenamiento por Insercion
void insertionSort(int* array, const int size)
{
	for(int i = 2;i < size; i++)
		for(int j = i; j > 0 && array[j] < array[j-1]; j--)
			swap(array[j],array[j-1]);
}

//Ordenamiento por Seleccion
void selectionSort(int* array, const int size)
{
	for(int i = 0; i < size-1; i++)
	{
		int aux = i;
		for(int j = i+1; j < size; j++)
			if(array[aux] > array[j])
				aux = j;

		if(i != aux)
			swap(array[i],array[aux]);
	}
}

//Ordenamiento por Burbuja
void bubbleSort(int* array, const int size)
{
	for(int i = 1;i < size; i++)
		for(int j = size-1; j >= i; --j)
			if(array[j-1] > array[j])
				swap(array[j],array[j-1]);
}

//Ordenamiento por Burbuja Mejorado
void improvedBubbleSort(int* array, const int size)
{
	for(int i = 1; i < size; i++)
	{
		bool cambio = false;
		for(int j = size-1; j >= i; --j)
			if(array[j-1] > array[j])
			{
				swap(array[j],array[j-1]);
				cambio = true;
			}
		if(!cambio)
			break;
	}
}

//Ordenamiento por ShellSort
void shellSort(int* array, const int size)
{
	for(int gap = size/2; gap > 0; gap /= 2)
		for(int i = gap; i < size; i++)
			for(int j = i-gap; j >= 0 && array[j+gap] < array[j]; j -= gap)
				swap(array[j+gap],array[j]);
}

//Ordenamiento por QuickSort
void quickSort(int* array, int primero, int ultimo)
{
	int i = primero;
	int j = ultimo;
	int pivote = array[((primero + ultimo) / 2)];

	while(i < j)
	{
		while(array[i] < pivote) i++;
		while(array[j] > pivote) j--;

		if(i <= j)
		{
			swap(array[i], array[j]);
			i++;
			j--;
		}

	}

	if(primero < j) quickSort(array, primero, j);
	if(i < ultimo) quickSort(array, i, ultimo);
}

//Busqueda Secuencial
bool sequientialSearch(const int* array, const int size, const int num)
{
	for(int i = 0; i < size; i++)
		if(array[i] == num)
			return true;
	return false;
}