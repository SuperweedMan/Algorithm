#pragma once
#include "UnoinFindBase.h"
#include <vector>
#ifdef DEBUG
#include <iostream>
#endif

class WeightedQuickUnion : public UnionFindBase {
private:
    std::vector<unsigned int> mArray;
    std::vector<unsigned int> mWeightArray;

public:
    WeightedQuickUnion(unsigned int n);
    ~WeightedQuickUnion();
    bool isConnected(unsigned int, unsigned int);
    void interLink(unsigned int, unsigned int);
    virtual unsigned int getAmount();

private:
    unsigned int getRoot(unsigned int);
};
