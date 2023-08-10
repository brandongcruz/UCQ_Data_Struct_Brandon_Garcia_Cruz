#include "LinkedList.h"

// Implementaci�n del m�todo append
template <typename T>
void LinkedList<T>::append(const T& value)
{
    LinkedListNode<T>* newNode = new LinkedListNode<T>(value);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        LinkedListNode<T>* current = head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Implementaci�n del m�todo remove
template <typename T>
void LinkedList<T>::remove(const T& value)
{
    if (!head)
    {
        return;
    }

    if (head->data == value)
    {
        LinkedListNode<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    LinkedListNode<T>* current = head;
    while (current->next)
    {
        if (current->next->data == value)
        {
            LinkedListNode<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

// Implementaci�n del m�todo clear
template <typename T>
void LinkedList<T>::clear()
{
    while (head)
    {
        LinkedListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
