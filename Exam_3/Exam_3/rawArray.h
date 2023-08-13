#pragma once

template <typename T>
class RawArray {
private:
    T* data;
    int size;

public:
    // Constructor que crea un RawArray con el tamaño especificado
    RawArray(int size);

    // Destructor que libera la memoria asignada para el arreglo
    ~RawArray();

    // Sobrecarga del operador [] para acceder a los elementos del arreglo,
    // permitiendo índices negativos para acceder a elementos desde el final
    T& operator[](int index);
};
