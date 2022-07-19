#include "Table.hpp"

using namespace std;

//Constructor
Table::Table()
{
}

//Destructor
Table::~Table()
{
}

//Calcula los tiempos que emplea un Metodo en Ordenar un array desordenado, uno ordenado y uno invertido
void Table::takeTime(int* array, int size, int method, string name, void function(int*,int))
{

	int copy[size]; //Copia del Array Original, para no perder la referencia

	//Variables encargadas de medir el tiempo
	clock_t start_time; //Inicio
	clock_t final_time; //Fin

	//Mostramos el Metodo actual a ejecutar
	cout << "\t - " << name << "..." << endl;
	methods[method].name = name;

	copyArray(copy,array,size); //Copiamos el valor del array original en el array copia

	//Para un Array Desordenado...

		cout << "\t\t- Array Desordenado" << endl;

		//Medimos el tiempo empleado en ordenar y lo registramos
		start_time = clock();
		function(copy,size);
		final_time = clock();

		methods[method].disordered = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;

	//

	//Para un Array Ordenado (tomamos el que acabamos de ordenar)...

		cout << "\t\t- Array Ordenado" << endl;

		//Medimos el tiempo empleado en ordenar y lo registramos
		start_time = clock();
		function(copy,size);
		final_time = clock();

		methods[method].ordered = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;

	//

	invertArray(copy,size);	//Invertimos el array ya ordenado

	//Para un Array Invertido...

		cout << "\t\t- Array Invertido" << endl;

		//Medimos el tiempo empleado en ordenar y lo registramos
		start_time = clock();
		function(copy,size);
		final_time = clock();

		methods[method].backward = ((double)(final_time - start_time)) / CLOCKS_PER_SEC;

	//
}

//Muestra los resultados obtenidos
void Table::print()
{
	cout << fixed << setprecision(6);
	cout << "\n-------------------------------------------------------------------------------------------------" << endl;
	cout << "|      Metodo/Array\t|\tDesordenado\t|\tOrdenado\t|\tInvertido\t|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t" << methods[0].name <<"\t|\t"<< methods[0].disordered <<" sg\t|\t" << methods[0].ordered << " sg\t|\t" << methods[0].backward << " sg\t|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t" << methods[1].name <<"\t|\t"<< methods[1].disordered <<" sg\t|\t" << methods[1].ordered << " sg\t|\t" << methods[1].backward << " sg\t|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t" << methods[2].name << "\t|\t"<< methods[2].disordered <<" sg\t|\t" << methods[2].ordered << " sg\t|\t" << methods[2].backward << " sg\t|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t" << methods[3].name << "\t|\t"<< methods[3].disordered <<" sg\t|\t" << methods[3].ordered << " sg\t|\t" << methods[3].backward << " sg\t|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t" << methods[4].name <<"\t|\t"<< methods[4].disordered <<" sg\t|\t" << methods[4].ordered << " sg\t|\t" << methods[4].backward << " sg\t|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
	cout << "|\t" << methods[5].name <<"\t|\t"<< methods[5].disordered <<" sg\t|\t" << methods[5].ordered << " sg\t|\t" << methods[5].backward << " sg\t|" << endl;
	cout << "-------------------------------------------------------------------------------------------------" << endl;
}

//Muestra los mejores tiempos para cada Categoria (Desordenado, Ordenado, Invertido)
void Table::betterTimes()
{

	cout << "\n\t------Desordenado------" << endl;

	//Ordenamos los metodos por ShellSort segun sus tiempos para un Array desordenado
	for(int gap = 3; gap > 0; gap /= 2)
		for(int i = gap; i < 6; i++)
			for(int j = i-gap; j >= 0 && methods[j+gap].disordered < methods[j].disordered; j -= gap)
				swap(methods[j+gap],methods[j]);

	//Mostramos los mejores resultados
	for(int i = 0; i < 6; i++)
		cout << "\t" << i+1 << "." << methods[i].name << ": " << methods[i].disordered << endl;

	cout << "\n\t------Ordenado------" << endl;

	//Ordenamos los metodos por ShellSort segun sus tiempos para un Array Ordenado
	for(int gap = 3; gap > 0; gap /= 2)
		for(int i = gap; i < 6; i++)
			for(int j = i-gap; j >= 0 && methods[j+gap].ordered < methods[j].ordered; j -= gap)
				swap(methods[j+gap],methods[j]);

	//Mostramos los mejores tiempos
	for(int i = 0; i < 6; i++)
		cout << "\t" << i+1 << "." << methods[i].name << ": " << methods[i].ordered << endl;

	cout << "\n\t------Invertido------" << endl;

	//Ordenamos los metodos por ShellSort segun sus tiempos para un Array desordenado
	for(int gap = 3; gap > 0; gap /= 2)
		for(int i = gap; i < 6; i++)
			for(int j = i-gap; j >= 0 && methods[j+gap].backward < methods[j].backward; j -= gap)
				swap(methods[j+gap],methods[j]);

	//Mostramos los tiempos obtenidos
	for(int i = 0; i < 6; i++)
		cout << "\t" << i+1 << "." << methods[i].name << ": " << methods[i].backward << endl;

}