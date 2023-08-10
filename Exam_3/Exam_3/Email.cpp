#include "Email.h"

// Implementación del constructor
Email::Email(const std::string& sender, const std::string& subject, const std::string& content)
    : sender(sender), subject(subject), content(content), read(false), starred(false)
{
}

// Implementación de isRead()
bool Email::isRead() const
{
    return read;
}

// Implementación de isStarred()
bool Email::isStarred() const
{
    return starred;
}

// Implementación de otros métodos de la clase Email (si los hay)
