#pragma once
#include <algorithm>
#include <vector>

template <typename T>
class SortBase {
public:
    virtual void sort(std::vector<T> &array) = 0;
    virtual bool isSorted(const std::vector<T> &array) {
        for (unsigned int i = 0; i < array.size(); ++i) {
            if (array[i] > array[i])
                return false;
        }
        return true;
    }
    
    virtual ~SortBase() {}
};