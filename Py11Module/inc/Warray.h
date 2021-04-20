#pragma once
#include <vector>


class Warray {
public:
    template<typename T>
    Warray(std::vector<T> && v){

    }
    private:
        std::vector<T> mArray;
};