#pragma once
#include "QuickFind.h"
#include "QuickUnion.h"
#include "WeightedQuickUnion.h"
#include <iostream>
#include <memory>
#include <vector>
#ifdef DEBUG
#include <iostream>
#endif

class MonteCarloSimulation {
private:
    std::shared_ptr<UnionFindBase> mUF;
    std::vector<bool> mMask;
    unsigned int mNumOfOpened;
    std::vector<unsigned int> mOrderOfOpen;
    unsigned int mN;
    unsigned int mThreshold;
    bool mFlag = true;

public:
    MonteCarloSimulation(std::shared_ptr<UnionFindBase>);
    MonteCarloSimulation(unsigned int n);
    ~MonteCarloSimulation() {
#ifdef DEBUG
        std::cout << "Call MonteCarLoSimulation distructor func." << std::endl;
#endif
    }
    void step();
    unsigned int run();

private:
    void open(unsigned int row, unsigned int col);
    bool isOpened(unsigned int row, unsigned col);
    void shuffle();
    void init();
};