#pragma once
#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <list>
#include <algorithm>

template <typename T>
class List {
private:
    std::list<T> data;

public:
    List() {} // Constructor por defecto
    List(T* in_data, int in_size); // Constructor con parámetros
    void PushBack(T element); // Agregar un elemento al final de la lista
    void Print(); // Imprimir los elementos de la lista
    void Reverse(); // Invertir el orden de los elementos en la lista
    void Unique(); // Eliminar los elementos duplicados en la lista
};

template <typename T>
List<T>::List(T* in_data, int in_size) {
    for (int i = 0; i < in_size; i++) {
        // Agregar cada elemento del array in_data a la lista data
        data.push_back(in_data[i]);
    }
}

template <typename T>
void List<T>::PushBack(T element) {
    data.push_back(element);
}

template <typename T>
void List<T>::Print() {
    typename std::list<T>::const_iterator it = data.begin();
    typename std::list<T>::const_iterator end = data.end();

    while (it != end) {
        std::cout << *it;

        if (++it != end) {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}

template <typename T>
void List<T>::Reverse() {
    data.reverse();
}

template <typename T>
void List<T>::Unique() {
    std::list<T> uniqueList;
    for (const auto& element : data) {
        if (std::find(uniqueList.begin(), uniqueList.end(), element) == uniqueList.end()) {
            uniqueList.push_back(element);
        }
    }
    data = uniqueList;
}

#endif
