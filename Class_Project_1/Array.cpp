#include "Array.h"
#include <iostream>

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