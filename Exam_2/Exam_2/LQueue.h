#pragma once
#include "ListE.h"
#include <iostream>
// if not defined -> si no est� definido
#ifndef LQUEUE 
#define LQUEUE


template <typename T>
class LQueue
{
private:
    List<T> data; // Usamos la clase List en lugar de std::list

public:
   
    void Enqueue(T value)
    {
        data.PushBack(value); // Utilizamos la funci�n PushBack de la clase List para agregar el elemento al final de la lista
    }

    void Dequeue()
    {
        data.PopFront(); // Utilizamos la funci�n PopFront de la clase List para eliminar el primer elemento de la lista
    }

    T front()
    {
        if (!data.IsEmpty())
        {
            return data.GetByIndex(0)->data;
        }
        else
        {
            
            throw std::runtime_error("La cola est� vac�a");
        }
    }

    T back()
    {
        int size = data.GetSize();
        if (size > 0)
        {
            return data.GetByIndex(size - 1)->data;
        }
        else
        {
            // Manejar el caso de cola vac�a como desees
            throw std::runtime_error("La cola est� vac�a");
        }
    }



    void PrintQueue()
    {
        data.Print(); // Utilizamos la funcion Print de la clase List para imprimir los elementos de la lista
    }

    bool IsEmpty() const
    {
        return data.IsEmpty(); // Verifica si la lista esta vacia
    }

    int GetSize() const
    {
        return data.GetSize(); // Obtiene el tamano de la lista
    }
};
#endif // LQUEUE

