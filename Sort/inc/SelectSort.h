#pragma once
#include "SortBase.h"
#include <vector>
#ifdef DEBUG
#include <iostream>
#endif

template <typename T>
class SelectSort : public SortBase<T> {
public:
    SelectSort();
    void sort(std::vector<T> &array);
    ~SelectSort();
};

template <typename T>
SelectSort<T>::SelectSort() {
#ifdef DEBUG
    std::cout << "Call constructor of class <SelecSort>." << std::endl;
#endif
}

template <typename T>
SelectSort<T>::~SelectSort() {
#ifdef DEBUG
    std::cout << "Call distructor of class <SelecSort>." << std::endl;
#endif
}

template <typename T>
void SelectSort<T>::sort(std::vector<T> &array) {
    unsigned int min_idx = 0;
    for (unsigned int i = 0; i < array.size(); ++i) {
        for (unsigned int j = i; j < array.size(); ++j) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        std::swap(array[i], array[min_idx]);
    }
}