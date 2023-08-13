#include "rawArray.h"

template <typename T>
RawArray<T>::RawArray(int size) : size(size) {
    data = new T[size];
}

template <typename T>
RawArray<T>::~RawArray() {
    delete[] data;
}

template <typename T>
T& RawArray<T>::operator[](int index) {
    // Ajustar el índice si es negativo para acceder a elementos desde el final
    int adjustedIndex = (index < 0) ? size + index : index;
    return data[adjustedIndex];
}
