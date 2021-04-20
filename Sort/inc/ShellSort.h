#pragma once
#include "SortBase.h"
#include <vector>
#ifdef DEBUG
#include <iostream>
#endif

template<typename T>
class ShellSort : public SortBase<T> {
public:
    ShellSort(){
#ifdef DEBUG
        std::cout << "Call constructor of class <ShellSort>." << std::endl;
#endif
    }
    ~ShellSort(){
#ifdef DEBUG
        std::cout << "Call distructor of class <ShellSort>." << std::endl;
#endif
    }
    void sort(std::vector<T> &array);
};

template<typename  T>
void ShellSort<T>::sort(std::vector<T> &array){
    
}