#include "customVector.h"

template <typename T>
CustomVector<T>::CustomVector(int size) : data(size) {}

template <typename T>
T& CustomVector<T>::operator[](int index) {
    // Ajustar el índice si es negativo para acceder a elementos desde el final
    int adjustedIndex = (index < 0) ? data.size() + index : index;
    return data[adjustedIndex];
}
