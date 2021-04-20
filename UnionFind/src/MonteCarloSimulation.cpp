#include "MonteCarloSimulation.h"
#include "MyTimer.h"
#include <time.h>
#include <math.h>

MonteCarloSimulation::MonteCarloSimulation(unsigned int n) {
    mUF = std::make_unique<WeightedQuickUnion>(n * n + 2);
    mN = n;
    init();
#ifdef DEBUG
    std::cout << "Call MonteCarLoSimulation constructor func." << std::endl;
#endif
}

MonteCarloSimulation::MonteCarloSimulation(std::shared_ptr<UnionFindBase> pInstance) {
    mUF = std::move(pInstance);
    mN = sqrt(mUF->getAmount() - 2);
    init();
#ifdef DEBUG
    std::cout << "Call MonteCarLoSimulation constructor func." << std::endl;
#endif
}

void MonteCarloSimulation::init() {
    std::vector<bool> temp(mN * mN + 2, false);
    mMask = std::move(temp); // 将mask初始化为都为false
    for (unsigned int i = 0; i < mN; ++i)
        mUF->interLink(mN * mN, i); // 将倒数第二个节点与第一行连通
    for (unsigned int j = mN * mN - 1; j >= mN * mN - mN; --j)
        mUF->interLink(mN * mN + 1, j); // 将最后一个节点与最后一行连通
    shuffle();
    mNumOfOpened = 0;
    mThreshold = 0;
}

void MonteCarloSimulation::open(unsigned int row, unsigned int col) {
    if (!mMask[row * mN + col]) { // 如果未打开
        mMask[row * mN + col] = true;
        if ((row != 0) && (mMask[(row - 1) * mN + col])) // 是否链接上一层
            mUF->interLink((row - 1) * mN + col, row * mN + col);
        if ((row != (mN - 1)) && (mMask[(row + 1) * mN + col])) // 是否链接下一层
            mUF->interLink((row + 1) * mN + col, row * mN + col);
        if ((col != 0) && (mMask[row * mN + col - 1]))
            mUF->interLink(row * mN + col - 1, row * mN + col);
        if ((col != mN - 1) && (mMask[row * mN + col + 1]))
            mUF->interLink(row * mN + col + 1, row * mN + col);
    }
}

bool MonteCarloSimulation::isOpened(unsigned int row, unsigned int col) {
    return mMask[row * mN + col];
}

unsigned int random(unsigned int upperLimit) {
    return rand() % upperLimit;
}

void MonteCarloSimulation::shuffle() {
    mOrderOfOpen.clear();
    mOrderOfOpen.reserve(mN * mN);
    mOrderOfOpen.push_back(0);
    srand(time(0));
    for (unsigned int i = 1; i < mN * mN; ++i) {
        mOrderOfOpen.push_back(i);
        std::swap(mOrderOfOpen[i], mOrderOfOpen[random(i)]);
    }
}

void MonteCarloSimulation::step() {
    unsigned int idx = mOrderOfOpen[mNumOfOpened];
    open(idx / mN, idx % mN);
    mNumOfOpened += 1;
    if (mUF->isConnected(mN * mN, mN * mN + 1) && mFlag) {
        mFlag = false;
        mThreshold = mNumOfOpened;
    }
}

unsigned int MonteCarloSimulation::run() {
    for (unsigned int i = 0; i < mOrderOfOpen.size(); ++i) {
        step();
    }
    return mThreshold;
}