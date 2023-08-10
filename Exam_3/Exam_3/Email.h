#pragma once
#include<string>
//Aqui vamos a definir miembros como el remitente, el asunto, 
//el contenido, la fecha, el estado de lectura/destacado, etc.

class Email
{
private:
    std::string sender;
    std::string subject;
    std::string content;
    bool read;
    bool starred;

public:
    Email(const std::string& sender, const std::string& subject, const std::string& content);

    // Agregar las funciones miembro isRead() e isStarred()
    bool isRead() const;
    bool isStarred() const;
    std::string getSender() const;
    std::string getSubject() const;
    // Otros métodos de la clase Email
};


