#include "Array.h"
#include <iostream>

// Construye el array con in_Size elementos y reserva un espacio de memoria del mismo tamano.
RawArray::RawArray(int in_Size) : Size(in_Size)
{
	InitialElement = new int[Size];
}

RawArray::~RawArray()
{
	std::cout << "Entrada destructor de RawArray" << '\n';
	delete[] InitialElement;
	std::cout << "Salida destructor" << '\n';

}

// Rellena el Array con el InitialValue deseado. 
void RawArray::Initial(int InitialValue)
{
	int* auxPosition = InitialElement;

	for (int i = 0; i < Size; i++)
	{
		*auxPosition = InitialValue;

		auxPosition++;
	}
}

// Imprime el contenido de un array.
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

//Remplaza todos los valores X del array por los valores Y deseados.
void RawArray::Replace(int X, int Y)
{
	int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		if (*auxPosition == X)
		{
			*auxPosition = Y;
		}
		auxPosition++;
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
}
