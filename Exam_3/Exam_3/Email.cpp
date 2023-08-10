#include "Email.h"

// Implementaci�n del constructor
Email::Email(const std::string& sender, const std::string& subject, const std::string& content)
    : sender(sender), subject(subject), content(content), read(false), starred(false)
{
}

// Implementaci�n de isRead()
bool Email::isRead() const
{
    return read;
}

// Implementaci�n de isStarred()
bool Email::isStarred() const
{
    return starred;
}

// Implementaci�n de otros m�todos de la clase Email (si los hay)
