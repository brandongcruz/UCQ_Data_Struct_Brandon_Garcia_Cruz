#include <iostream>
#include "Array.h"

//Constructor de la clase: el prametro "in_Size" se utiliza para determinar el tamano del array dinamico "InitialElement". 
//"New init " funciona para asignar la memoria "Size" que utilizara el arreglo
RawArray::RawArray(int in_Size) : Size(in_Size)
{
	InitialElement = new int[Size];

<<<<<<< HEAD
	// Restriccion del tamano del arreglo. 

=======
	
>>>>>>> 8a061c61d1cc8891e1af8cd9f29b7bd25c054032
}



//Destructor de la clase. Se encarga de liberar la memoria asignada  dinamicamente apra el arreglo.
RawArray::~RawArray()
{	
	std::cout << "Entrada destructor de RawArray" << '\n';
	delete[] InitialElement;
	std::cout << "Salida destructor" << '\n';

}

//Esta funcion se utiliza para inicializar todos los elementos del arreglo con un valor inicial. 
//InitialValue representa el valor con el que se desea inicializar los elementos. 
void RawArray::Initial(int InitialValue)
{

	int* auxPosition = InitialElement; 

	//Utilizamos el for para rrecorrer los elementos del arreglo y asignarles el valor "InitialValue"
	for (int i = 0; i < Size; i++)
	{
		*auxPosition = InitialValue;

		auxPosition++; 
	}
}

//Esta funcion se utiliza para imprimir en la consola todos los valores de los elementos del arreglo.
void RawArray::Print()
{
	int* auxPosition = InitialElement; 

	for (int i = 0; i < Size; i++)
	{
		std::cout << *auxPosition << ", "; 

		auxPosition++; 
	}
	std::cout << '\n';
}


//Utiliza un puntero auxPosition para recorrer los elementos del arreglo y compara el valor del contenido de cada espacio de memoria con utilizando el operador *. 
//Si el valor X coincide, asigna Y al elemento mediante el operador de referencia *.
//Luego, incrementa el puntero auxPosition para avanzar al siguiente elemento y realizar la misma accion.
void RawArray::Replace(int X, int Y)
{
	int* auxPosition = InitialElement;

	//flag Es un indicador que usaremos para indicar si se realizo algun reemplazo 

	bool flag = false; 

	for (int i = 0; i < Size; i++)
	{
		if (*auxPosition == X)
		{
			*auxPosition = Y;

			// Si Existe algun numero que deba ser sustituido, la bandera cambiara de estado a true
			flag = true; 
		}
		auxPosition++;
	}

	// Si la bandera es true le deja saber al usuario que hubo un cambio, de lo contrario le hara saber que no habin cambios que realizar. 
	if (flag)
	{
		std::cout << "Se realizo el reemplazo de " << X << " por " << Y << std::endl;
	}
	else
	{
		std::cout << "No se encontro ningun valor igual a " << X << ". No se realizo ningun cambio." << std::endl;
	}
}


void RawArray::TestCaseReplace(int Values)
{
<<<<<<< HEAD
	int* auxPosition = InitialElement; 

	for (int i = 0; i < Size; i++)
	{
		*auxPosition = Values++;

		auxPosition;
	}
=======
	InitialElement[0] = 1;
	InitialElement[1] = 5;
	InitialElement[2] = 9;
	InitialElement[3] = 0;
	InitialElement[4] = 1;
	InitialElement[5] = 5;
	// Restriccion del tamano del arreglo. 

	if (Size > 6)
	{
		std::cout << "Advertencia: El Size especificado es mayor que el numero de valores asignados. "\
			"Los valores restantes se inicializaran a 0." << std::endl;



		// Inicializar los valores restantes en 0
		for (int i = 6; i < Size; i++)
		{
			InitialElement[i] = 0;
		}
	}
	else if (Size < 6) {
		std::cout << "Error: El size especificado es menor que el size minimo requerido (6)." << std::endl;
		return;
	}
}

// A PARTIR DE AQUI SE CONSTRUYERON LAS FUNCIONES PARA REALIZAR EL EXAMEN.

//Asignar valor V a uno de cada X elementos del RawArray, donde X y V son un entero.
void RawArray::AssignEveryXElements(int v, int x)
{
	int* auxPosition = InitialElement;
	int counter = 1;

	for (int i = 0; i < Size; i++)
	{
		if (counter == x)
		{
			*auxPosition = v;
			counter = 1;
		}
		else
		{
			counter++;
		}
		auxPosition++;
	}

}

//Ordena los elementos del RawArray de menor a mayor
void RawArray::SortFunction()
{

}

//Añade al RawArray "A" todos los elementos del RawArray "B", Manteniendo los elementos de "A" al principio y despues agregando los elementos de "B"
void AppendArray(RawArray arrayToAppend)
{

}

//Modifica el tamano del RawArray para igualar el numero de elementos de newSize. 
//Si newSize es mayor al Size actual del RawArray, Conserva el total de sus Size_elementos 
//Si newSize es menor al Size actual del RawArray; conserva los primeros elementos hasta newSize 
void RawArray::SetSize(int newSize)
{

}

//Añade los arrayToInsert.Size-elementos al RawArray que llamó la función Insert, a partir del elemento en startIndex.
void RawArray::Insert(RawArray arrayToInsert, int startIndex)
{

}

//Suma elemento por elemento los valores del Array "A" con los valores del array "B". 
//A y B tienen el mismo Size. 
//Retorna un RawArray distinto de A y B con los resultados de la suma.
void RawArray::SumArrays(RawArray A, RawArray B)
{

}

//Recibe un valor X, si encuentra un elemento con dicho valor dentro del RawArray, regresa la posición de dicho elemento.
//Si no encuentra el valor X dentro del RawArray, regresa -1.
int RawArray::GetIndexOf(int x)
{
	return -1;
}

//Regresar la posición del último elemento del RawArray con el valor X dado. 
//Si no encuentra ningun elemento con valor x, regresar -1.
int RawArray::GetLastOf(int x)
{
	return -1;
}

//Recibe un valor X; regresa el indice de todos los elementos con valor X
//Si no encuentra ningun elemento condicho valor, regresa un array cuyo primer y único elemento es -1.
RawArray RawArray::GetIndicesOf(int x)
{
	return NULL;
>>>>>>> 8a061c61d1cc8891e1af8cd9f29b7bd25c054032
}
