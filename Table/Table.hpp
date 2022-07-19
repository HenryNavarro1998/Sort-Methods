#ifndef Table_hpp
#define Table_hpp value

//Librerias Importadas
#include <iostream>
#include <iomanip>
#include <ctime>
#include "../Array/Array.hpp"

//Estructura Metodo, almacena el nombre y los tiempos de un metodo
struct Method{
	std::string name;
	double disordered;
	double ordered;
	double backward;
};

//Clase Tabla, registra los valores arrojados por todos los Metodos de Ordenamiento
class Table{
	private:
		Method methods[6]; //Metodos

	public:
		Table(); //Constructor
		~Table(); //Destructor
		void takeTime(int*,int,int,std::string,void(int*,int)); //Mide el tiempo que emplea un Metodo de Ordenamiento para un array desordenado, ordenado e invertido
		void print(); //Muestra la Tabla (Los resultados obtenidos)
		void betterTimes(); //Ordena los metodos segun cada categoria (ordenado, desordenado o invertudo) y lo muestra por consola
};

#endif