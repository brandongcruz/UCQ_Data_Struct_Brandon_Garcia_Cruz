#pragma once

#include <vector>

template <typename T>
class CustomVector {
private:
    std::vector<T> data;

public:
    // Constructor que crea un CustomVector con el tamaño especificado
    CustomVector(int size);

    // Sobrecarga del operador [] para acceder a los elementos del vector,
    // permitiendo índices negativos para acceder a elementos desde el final
    T& operator[](int index);
};

