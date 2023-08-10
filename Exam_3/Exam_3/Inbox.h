#pragma once
#include <unordered_map>
#include "Email.h"
#include "LinkedList.h"

//Aqu� vamos a definir los m�todos para agregar correos electr�nicos,
//eliminar correos electr�nicos y filtrar correos electr�nicos seg�n diferentes criterios. 

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

// Implementaci�n de los m�todos

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
        // Retornar una lista vac�a o manejar el caso de filtro no v�lido
        return LinkedList<Email*>();
    }
}
