#pragma once
#include "UnoinFindBase.h"
#include <vector>
#ifdef DEBUG
#include <iostream>
#endif

class QuickUnion : public UnionFindBase {
private:
    std::vector<unsigned int> mArray;

public:
    QuickUnion(unsigned int n);
    ~QuickUnion();
    bool isConnected(unsigned int, unsigned int);
    void interLink(unsigned int, unsigned int);
    virtual unsigned int getAmount();

private:
    unsigned int getRoot(unsigned int);
};