#include "Array.h"
#include <iostream>


//Constructor de la clase: el prametro "in_Size" se utiliza para determinar el tamano del array dinamico "InitialElement". 
//"New init " funciona para asignar la memoria "Size" que utilizara el arreglo
RawArray::RawArray(int in_Size) : Size(in_Size)
{
	InitialElement = new int[Size];

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
		std::cout << " \nSe realizo el reemplazo de " << X << " por " << Y << std::endl;
	}
	else
	{
		std::cout << " \nNo se encontro ningun valor igual a " << X << ". No se realizo ningun cambio." << std::endl;
	}
}


void RawArray::TestCaseReplace(int Values)
{

	int* auxPosition = InitialElement;

	//Utilizamos el for para rrecorrer los elementos del arreglo y asignarles el valor "InitialValue"
	for (int i = 0; i < Size; i++)
	{
		*auxPosition = Values++;

		auxPosition++;
	}
}

// A PARTIR DE AQUI SE CONSTRUYERON LAS FUNCIONES PARA REALIZAR EL EXAMEN.

//Asignar valor V a uno de cada X elementos del RawArray, donde X y V son un entero.
void RawArray::AssignEveryXElements(int v, int x)
{
	int* auxPosition = InitialElement;
	int counter = 1;

	bool flag = false;

	for (int i = 0; i < Size; i++)
	{
		if (counter == x)
		{
			*auxPosition = v;
			counter = 1;

			flag = true;
		}
		else
		{
			counter++;
		}
		auxPosition++;
	}


	if (flag)
	{
		std::cout << " \nSe realizo el remplazo del valor original en cada " << x << " casillas por el valor de " << v << std::endl;
	}
	else
	{
		std::cout << "No se encontro ningun valor igual a " << x << ". No se realizo ningun cambio." << std::endl;
	}
}


//Ordena los elementos del RawArray de menor a mayor
void RawArray::SortFunction()
{
	int* auxPosition = InitialElement;

	bool flag = true;

	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - 1; j++)
		{
			//Se hace una comparativa entre cada componente del arreglo para determinar cual es el mayor 
			if (InitialElement[j] > InitialElement[j + 1])
			{
				// se actualiza la variable auxiliar de acuerdo al valor que sea menor.
				int aux = InitialElement[j];
				InitialElement[j] = InitialElement[j + 1];
				InitialElement[j + 1] = aux;
			}
		}
	}
 
	if (flag)
	{
		std::cout << " \nSe realizo un ordenamiendo burbuja al array, ahora estan acomodados de menor a mayor  \n";
	}
}

//Añade al RawArray "A" todos los elementos del RawArray "B", Manteniendo los elementos de "A" al principio y despues agregando los elementos de "B"
void RawArray::AppendArray(RawArray arrayToAppend)
{
	// creamos un nuevo objeto RawArray con el tamano definido por el Size de myArray + el Size del nuevo Arreglo 
	int newSize = Size + arrayToAppend.Size;
	
	RawArray newArray(newSize);

	// Copiar los elementos de myArray al nuevo arreglo
	for (int i = 0; i < Size; i++)
	{
		newArray.InitialElement[i] = InitialElement[i];
	}

	// copiamos los elementos del arrayToAppend al nuevo arreglo. modificamos en limite de la iteracion al tamano del arrayToAppend
	for (int i = 0; i < arrayToAppend.Size; i++)
	{
		// Copiamos los elementos empezando desde el indice Size
		newArray.InitialElement[Size + i] = arrayToAppend.InitialElement[i];
	}

	// Actualizar el tamaño del nuevo arreglo
	newArray.Size = newSize;

	// Imprimir el nuevo arreglo
	newArray.Print();
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
	int* auxPosition = InitialElement;

	for (int i = 0; i < Size; i++)
	{
		if (*auxPosition == x)
		{
			 return i;  // Se encontró el elemento, se devuelve su posición

		}

		auxPosition++;
	}


	return -1;  // No se encontró el elemento, se devuelve -1auxPosition++;
}

//Regresar la posición del último elemento del RawArray con el valor X dado. 
//Si no encuentra ningun elemento con valor x, regresar -1.
int RawArray::GetLastOf(int x)
{
	int* auxPosition = InitialElement;
	int lastPosition = -1;

	for (int i = 0; i < Size; i++)
	{
		if (*auxPosition == x)
		{
			lastPosition = i;  // Actualizar la última posición encontrada
		}

		auxPosition++;
	}

	if (lastPosition == -1)
	{
		std::cout << " \n No se encontro ninguna posicion con valor " << x << std::endl;
	}
	else
	{
		std::cout << "La posicion del elemento elegido es: " << lastPosition << std::endl;
	}


	return lastPosition;
}

//Recibe un valor X; regresa el indice de todos los elementos con valor X
//Si no encuentra ningun elemento condicho valor, regresa un array cuyo primer y único elemento es -1.
RawArray RawArray::GetIndicesOf(int x)
{

	RawArray indices(Size);  // Crea un objeto RawArray de tamano Size para almacenar los indices

		int* auxPosition = InitialElement;
		bool flag = false;

		for (int i = 0; i < Size; i++)
		{
			if (*auxPosition == x)
			{
				indices.InitialElement[i] = i;  // Usamos el puntero InitialElement para llenar el objeto indices.
				flag = true;
			}
			else
			{
				indices.InitialElement[i] = -1;  // Asignamos -1 para senalar que el valor del indice no coincide con lo que se busca
			}

			auxPosition++;
		}

		if (flag)
		{
			std::cout << "No se encontro una coincidencia del valor " << x << " en las casillas marcadas con -1\n";
			indices.Print();
		}
		else
		{
			std::cout << "No se encontro NINGUN valor " << x << " en el arreglo \n";
			indices.Size = 1;  // definimos el tamano que tendra el objeto 
			indices.InitialElement[0] = -1;  // Asigna -1 como unico elemento en el objeto indices
			indices.Print();  // imprimimos el objeto indices
		}
		return indices;
}
