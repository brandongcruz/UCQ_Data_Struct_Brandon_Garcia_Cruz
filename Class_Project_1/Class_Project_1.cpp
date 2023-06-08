// Class_Project_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
#include "Array.cpp"


#define MY_NULL 0 

int main()
{
// Para la realizacion no se incluyo una restriccion en el codigo si se intenta ingresar valores distintos de int debido a que no se considero necesario
// Pues esta restriccion se encuentra implicita en la declaracion del RawArray el cual unicamente recibe valores int.
    std::cout << "Hello Everyone\n";


    RawArray myArray(10);

    myArray.TestCaseReplace(1);
 
    std::cout << " \nArray Original: \n";

    myArray.Print(); 

    myArray.Replace(9, 0);

    std::cout << " \nArray Modificado: \n"; 

    myArray.Print();
    
    //APARTADO PARA EL EXAMEN 

    //AssignEveryXElements
     std::cout << "\nApartado examen \n";
    std::cout << "Funcion AssignEveryXElements \n";
    std::cout << " \nArray Original: \n";
    myArray.Print();
    myArray.AssignEveryXElements(5, 2);
    std::cout << " \nArray Modificado: \n";
    myArray.Print();

    //SortFunction
    std::cout << "\nSortFunction\n";
    std::cout << " \nArray Original: \n";
    myArray.Print();
    myArray.SortFunction();
    std::cout << " \nArray Ordenado: \n";
    myArray.Print();
    
    //GetIndexOf Function
    std::cout << "\nGetIndexOf Function \n";
    std::cout << " \nArray Original: \n";
    myArray.Print(); 
    int index = myArray.GetIndexOf(5);
    std::cout << "La posición del elemento elegido es: " << index << std::endl;
    
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
