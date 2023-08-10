#include "LinkedList.h"

// Implementación del método append
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

// Implementación del método remove
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

// Implementación del método clear
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
