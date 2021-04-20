#pragma once
#include "SortBase.h"
#ifdef DEBUG
#include <iostream>
#endif

template <typename T>
class InsertSort : public SortBase<T> {
public:
    InsertSort() {
// #ifdef DEBUG
//         std::cout << "Call constructor of class <InsertSort>." << std::endl;
// #endif
    }
    ~InsertSort() {
// #ifdef DEBUG
//         std::cout << "Call distructor of class <InsertSort>." << std::endl;
// #endif
    }
    void sort(std::vector<T> &array);
};

template <typename T>
void InsertSort<T>::sort(std::vector<T> &array) {
    for (unsigned int i = 0; i < array.size(); ++i) {
        for (unsigned int j = i; j > 0; --j) {
            if (array[j] > array[--j])
                break;
            else
                std::swap(array[j], array[--j]);
        }
    }
}