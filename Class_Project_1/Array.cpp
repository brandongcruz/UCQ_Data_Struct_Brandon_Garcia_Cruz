#include "Array.h"
#include <iostream>


//Constructor de la clase: el prametro "in_Size" se utiliza para determinar el tamano del array dinamico "InitialElement". 
//"New init " funciona para asignar la memoria "Size" que utilizara el arreglo
RawArray::RawArray(int in_Size) : Size(in_Size)
{
	InitialElement = new int[Size];
	
	// just added 
	
	InitialElement[0] = 1;
	InitialElement[1] = 5;
	InitialElement[2] = 9;
	InitialElement[3] = 0;
	InitialElement[4] = 1;
	InitialElement[5] = 5;
}

//
RawArray::~RawArray()
{	
	std::cout << "Entrada destructor de RawArray" << '\n';
	delete[] InitialElement;
	std::cout << "Salida destructor" << '\n';

}

void RawArray::Initial(int InitialValue)
{
	int* auxPosition = InitialElement; 
	
	for (int i = 0; i < Size; i++)
	{
		*auxPosition = InitialValue;

		auxPosition++; 
	}
}

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