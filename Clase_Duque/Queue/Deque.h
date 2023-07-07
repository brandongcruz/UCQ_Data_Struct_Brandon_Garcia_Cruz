#pragma once
#include <iostream>

template <typename T>
class Deque
{
private:
	// Variables que tiene que tener:
	// Donde vamos a guardar los datos.
	T* InitialElement;
	int _head;
	int _tail;
	int _size; // cuanta memoria est� pedida actualmente.
	int _currentElements;  // Nos indica cu�ntos elementos hay actualmente dentro de la Queue.

	bool _isDynamic;

public:
	Deque(int size, bool Dynamic = true) : _size(size), _isDynamic(Dynamic)
	{
		// pedimos _size bloques de memoria, cada uno de tama�o igual al tipo T del template.
		InitialElement = new T[_size];
		// Tenemos que inicializar los valores de _head y _tail, y ambos inician en 0.
		_head = 0;
		_tail = 0;
		_currentElements = 0;  // porque iniciamos con una Queue vac�a.
	}

	~Deque()
	{
		delete[] InitialElement;  // liberamos la memoria pedida para nuestro arreglo de tipo T.
	}

	void FrontEnqueue(T element)
	{
		if (Full())
		{
			if (_isDynamic == true)
			{
				// Pedir m�s memoria
				T* AuxPointer = new T[_size * 2];

				// Copiar lo de la vieja memoria a esta nueva memoria
				for (int i = 0; i < _currentElements; i++)
				{
					AuxPointer[i] = InitialElement[(i + _head) % _size];
				}

				// Cambiar a d�nde apunta InitialElement
				InitialElement = AuxPointer;
				_size = _size * 2;

				// Necesitamos tambi�n actualizar los valores de head y tail.
				_head = 0;
				_tail = _currentElements;
			}
			else
			{
				std::cout << "Deque llena" << '\n';
				return;
			}
		}

		// Calcular la nueva posici�n de _head
		_head = (_head - 1 + _size) % _size;

		// Agregar el elemento en la nueva posici�n de _head
		InitialElement[_head] = element;

		// Incrementar el n�mero de elementos actuales
		_currentElements++;
	}


	// A�ade el elemento "element" en la posici�n Tail de la Queue, e incrementa el valor de Tail en 1.
	void EnqueueBack(T element)
	{
		if (Full() == true)
		{
			if (_isDynamic == true)
			{
				// Pedir m�s memoria
				T* AuxPointer = new T[_size * 2];
				// dato cultural, el tama�o por defecto de las estructuras de datos es una potencia de 2, por ejemplo 128
				// Copiar lo de la vieja memoria a esta nueva memoria
				for (int i = 0; i < _currentElements; i++)
				{
					AuxPointer[i] = InitialElement[(i + _head) % _size];
				}

				// borrar la memoria vieja
				delete[] InitialElement;
				// cambiar a d�nde apunta InitialElement
				InitialElement = AuxPointer;
				_size = _size * 2; // _size *= 2; es lo mismo

				// Necesitamos tambi�n actualizar los valores de head y tail.
				_head = 0;
				_tail = _currentElements;  // tambi�n podr�a haber sido _tail = _size, pero antes del size*2.

				// lo podr�amos a�adir aqu�, pero al pensar bien las ramificaciones de la ejecuci�n, nos lo podemos ahorrar.
				// InitialElement[_top] = ElementToPush;
				// _top++; // incrementamos el tope en una unidad (_top++; es lo mismo que _top = _top + 1;)
			}
			// 
			std::cout << "Deque llena" << '\n';
		}

		// Poner element en donde Tail nos diga.
		InitialElement[_tail] = element;
		if (_tail == _size - 1)
		{
			// Hay que ciclar el valor de tail
			_tail = 0;
		}
		else
		{
			_tail++;
		}

		_currentElements++;
	}

	// Quita el elemento de la posici�n Head de la Queue, e incrementa el valor de Head en 1.
	void FrontDequeue()
	{
		// Antes de quitar elementos, hay que checar que s� hay al menos un elemento por quitar.
		// IMPORTANTE.
		if (Empty())
		{
			std::cout << "ERROR, tratando de quitar elementos de la Deque, pero no hay. Underflow." << '\n';
			return;  // salimos de la funci�n para evitar modificar otra cosa.
		}

		_head++;
		// Primero ciclamos el valor de head
		_head = _head % _size;
		// InitialElement[_head] = NULL;  // OPCIONAL
		// Incrementamos Head en 1
		_currentElements--;

		if (_isDynamic == true)
		{
			// checar cu�ntos elementos quedan
			if (_currentElements <= _size / 4)
			{
				// entonces reducimos la memoria que ocupa esta Queue.

				// Pedimos nueva memoria
				T* AuxPointer = new T[_size / 2];

				// copiamos de lo viejo a lo nuevo
				for (int i = 0; i < _currentElements; i++)
				{
					AuxPointer[i] = InitialElement[(i + _head) % _size];
				}

				// borramos lo viejo
				delete[] InitialElement;
				InitialElement = AuxPointer;
				_size = _size / 2;

				// actualizamos head y tail.
				_head = 0;
				_tail = _currentElements;

			}
		}
	}

	void BackDequeue()
	{
		if (Empty())
		{
			std::cout << "ERROR, tratando de quitar elementos de la Deque, pero no hay. Underflow." << '\n';
			return;
		}

		// Calculamos la nueva posici�n de tail
		if (_tail == 0)
		{
			_tail = _size - 1;
		}
		else
		{
			_tail--;
		}

		// Decrementamos el n�mero de elementos actuales
		_currentElements--;

		if (_isDynamic == true)
		{
			// Verificamos si es necesario reducir la memoria ocupada por la Deque
			if (_currentElements <= _size / 4)
			{
				// Pedimos nueva memoria
				T* AuxPointer = new T[_size / 2];

				// Copiamos los elementos de la memoria actual a la nueva memoria
				for (int i = 0; i < _currentElements; i++)
				{
					AuxPointer[i] = InitialElement[(i + _head) % _size];
				}

				// Liberamos la memoria actual
				delete[] InitialElement;
				InitialElement = AuxPointer;
				_size = _size / 2;

				// Actualizamos head y tail
				_head = 0;
				_tail = _currentElements;
			}
		}
	}


	// Regresa el valor del elemento en el �ndice Head de la Queue
	T Front()
	{
		if (Empty())
		{
			std::cout << "La Queue est� vac�a" << std::endl;
			// Podr�as lanzar una excepci�n en lugar de imprimir un mensaje y devolver un valor predeterminado
			// throw std::runtime_error("La Queue est� vac�a");
			return T(); // Devolver un valor predeterminado del tipo T
		}

		return InitialElement[_head];
	}

	// Regresa el valor del elemento en el �ndice Tail de la Queue
	T Back()
	{
		if (Empty())
		{
			// Manejar el caso de Queue vac�a
			std::cout << "Error: La Queue est� vac�a. No se puede obtener el elemento al final.";
			return T();  // Retornar un valor predeterminado en caso de error
		}

		int backIndex = (_tail - 1 + _size) % _size;
		return InitialElement[backIndex];
	}

	bool Empty()
	{
		// if (_head == _tail)
		// 	return true;

		if (_currentElements == 0)
			return true;  // si no hay elementos, quiere decir que est� vac�a la Queue.

		return false;
	}

	bool Full()
	{
		// Si le caben _size elementos, y actualmente tiene dentro _size elementos, entonces est� llena.
		if (_size == _currentElements)
			return true;

		// if (_head == (_tail ) || (_head == 0 && _tail == _size-1))
		//	return true;

		return false;
	}

	void PrintDeque() 
	{
		// Cu�ntas veces deber�a imprimir letras? _currentElements;
		for (int i = 0; i < _currentElements; i++)
		{
			std::cout << InitialElement[(i + _head) % _size] << ", ";
		}
		std::cout << '\n';
	}

	// Imprimir // No es exactamente igual que la de Stack ni la de RawArray.
	//void Print()
	//{
	//	for (int i = 0; i < _size; i++)
	//	{
	//		std::cout << InitialElement[i] << ", ";
	//	}
	//	std::cout << '\n';
	//}


};


