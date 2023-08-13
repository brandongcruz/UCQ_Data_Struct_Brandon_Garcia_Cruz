#include <iostream>
#include "Email.h"
#include "Inbox.h"
#include "LinkedList.h"

#include "customVector.h"
#include "rawArray.h"

int main()
{

    //Parte 1 del Examen 

    // Crear un CustomVector de caracteres
    CustomVector<char> myVector(5);
    myVector[0] = 'a';
    myVector[1] = 'b';
    myVector[2] = 'c';
    myVector[3] = 'd';
    myVector[4] = 'e';

    // Acceder a elementos desde el final usando �ndices negativos
    std::cout << "CustomVector: " << myVector[-1] << std::endl;

    // Crear un RawArray de enteros y asignar valores
    RawArray<int> myArray(5);
    for (int i = 0; i < 5; i++) {
        myArray[i] = i + 1;
    }

    // Acceder a elementos desde el final usando �ndices negativos
    std::cout << "RawArray: " << myArray[-1] << std::endl;



    // Fin Parte 1
    std::cout << "Hello Professor!\n";
    std::cout << "Examen tercer parcial \n";
    std::cout << "Projecto Email";
    //Parte 3 del examen
    //Vamos a Combinar diferentes estructuras para realizar el projecto
    //Usaremos una Linked list para almacenar correos electr�nicos:
    //Para mantener un registro de todos los correos electr�nicos en orden de llegada.
    //Cada nodo en la lista podr�a contener la informaci�n relevante de un correo electr�nico, 
    //como remitente, asunto, contenido, fecha, estado de lectura/destacado, etc.
    // y una hash Table para filtrado r�pido

    // Crear una instancia de Inbox
    Inbox inbox;

    // Agregar algunos correos electr�nicos para demostraci�n
    Email email1("user1@example.com", "Saludo", "�Hola! �C�mo est�s?");
    Email email2("user2@example.com", "Oferta", "�Oferta especial por tiempo limitado!");
    Email email3("user3@example.com", "Recordatorio", "Reuni�n a las 3 PM");

    // Agregar correos a Inbox
    inbox.addEmail(&email1);
    inbox.addEmail(&email2);
    inbox.addEmail(&email3);

    // Marcar algunos correos como le�dos y destacados
    email1.isRead();
    email2.isRead();
    email2.isStarred();

    // Filtrar y mostrar correos le�dos
    std::cout << "Correos le�dos:\n";
    LinkedList<Email*> readEmails = inbox.filterEmails("read");
    for (LinkedListNode<Email*>* node = readEmails.begin(); node != nullptr; node = node->next)
    {
        Email* email = node->data;
        std::cout << "De: " << email->getSender() << ", Asunto: " << email->getSubject() << "\n";
    }

    // Filtrar y mostrar correos no le�dos
    std::cout << "Correos no le�dos:\n";
    LinkedList<Email*> unreadEmails = inbox.filterEmails("unread");
    for (LinkedListNode<Email*>* node = unreadEmails.begin(); node != nullptr; node = node->next)
    {
        Email* email = node->data;
        std::cout << "De: " << email->getSender() << ", Asunto: " << email->getSubject() << "\n";
    }

    // Filtrar y mostrar correos destacados
    std::cout << "Correos destacados:\n";
    LinkedList<Email*> starredEmails = inbox.filterEmails("starred");
    for (LinkedListNode<Email*>* node = starredEmails.begin(); node != nullptr; node = node->next)
    {
        Email* email = node->data;
        std::cout << "De: " << email->getSender() << ", Asunto: " << email->getSubject() << "\n";
    }

    // Filtrar y mostrar correos no destacados
    std::cout << "Correos no destacados:\n";
    LinkedList<Email*> unstarredEmails = inbox.filterEmails("unstarred");
    for (LinkedListNode<Email*>* node = unstarredEmails.begin(); node != nullptr; node = node->next)
    {
        Email* email = node->data;
        std::cout << "De: " << email->getSender() << ", Asunto: " << email->getSubject() << "\n";
    }

    // Mostrar todos los correos
    std::cout << "Todos los correos:\n";
    LinkedList<Email*> allEmails = inbox.filterEmails("all");
    for (LinkedListNode<Email*>* node = allEmails.begin(); node != nullptr; node = node->next)
    {
        Email* email = node->data;
        std::cout << "De: " << email->getSender() << ", Asunto: " << email->getSubject() << "\n";
    }


   




    return 0;
}