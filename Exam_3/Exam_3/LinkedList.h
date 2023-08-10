#pragma once

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T>* next;

    LinkedListNode(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    LinkedListNode<T>* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void append(const T& value);
    void remove(const T& value);
    void clear();

    // Otros métodos según sea necesario
    LinkedListNode<T>* begin() const { return head; }
    LinkedListNode<T>* end() const { return nullptr; }
};


// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

// Agrega un elemento al final
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

// Eliminar un elemento
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

// Limpia la lista
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
