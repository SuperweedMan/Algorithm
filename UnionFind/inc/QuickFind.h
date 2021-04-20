#pragma once
#include "UnoinFindBase.h"
#include <vector>
#ifdef DEBUG
#include <iostream>
#endif

class QuickFind : public UnionFindBase {
private:
    std::vector<unsigned int> pArray;

public:
    QuickFind(unsigned int);
    ~QuickFind() {
#ifdef DEBUG
        std::cout << "Call QuickFind distructor func." << std::endl;
#endif
    }
#ifdef DEBUG
    QuickFind(const QuickFind &) { std::cout << "Call <copy constructor> of class <QuickFind>." << std::endl; }
#endif
    bool isConnected(unsigned int, unsigned int);
    void interLink(unsigned int, unsigned int);
    virtual unsigned int getAmount();
};
