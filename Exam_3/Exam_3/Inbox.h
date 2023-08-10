#pragma once
#include <unordered_map>
#include "Email.h"
#include "LinkedList.h"

//Aquí vamos a definir los métodos para agregar correos electrónicos,
//eliminar correos electrónicos y filtrar correos electrónicos según diferentes criterios. 

class Inbox
{
private:
    std::unordered_map<std::string, LinkedList<Email*>> emailFilters;

public:
    Inbox() {}  // Constructor (si es necesario)

    void addEmail(Email* email);
    void deleteEmail(Email* email);
    LinkedList<Email*> filterEmails(std::string filterType);
};

// Implementación de los métodos

void Inbox::addEmail(Email* email)
{
    emailFilters["all"].append(email);

    if (email->isRead())
    {
        emailFilters["read"].append(email);
    }

    if (email->isStarred())
    {
        emailFilters["starred"].append(email);
    }
}

void Inbox::deleteEmail(Email* email)
{
    emailFilters["all"].remove(email);

    if (email->isRead())
    {
        emailFilters["read"].remove(email);
    }

    if (email->isStarred())
    {
        emailFilters["starred"].remove(email);
    }
}

LinkedList<Email*> Inbox::filterEmails(std::string filterType)
{
    auto it = emailFilters.find(filterType);
    if (it != emailFilters.end())
    {
        return it->second;
    }
    else
    {
        // Retornar una lista vacía o manejar el caso de filtro no válido
        return LinkedList<Email*>();
    }
}
