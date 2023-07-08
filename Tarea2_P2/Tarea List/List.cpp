#include <vector>

int main() {
    std::vector<int> myVector = { 1, 1, 2, 3, 4, 2, 3, 1 };

}
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
    List(const std::initializer_list<T>& elements); // Constructor con parámetros
    void PushBack(T element); // Agregar un elemento al final de la lista
    void Print(); // Imprimir los elementos de la lista
    void Reverse(); // Invertir el orden de los elementos en la lista
    void Unique(); // Eliminar los elementos duplicados en la lista
};

template <typename T>
List<T>::List(const std::initializer_list<T>& elements) {
    for (const auto& element : elements) {
        data.push_back(element);
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