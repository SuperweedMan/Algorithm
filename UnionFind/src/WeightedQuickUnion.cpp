#include "WeightedQuickUnion.h"

WeightedQuickUnion::WeightedQuickUnion(unsigned int n) {
    mArray.reserve(n); // 初始化各个节点，每个节点的root节点为本身，存储在对应位置。
    for (unsigned int i = 0; i < n; ++i)
        mArray.push_back(i);
    mWeightArray = std::move(std::vector<unsigned int>(n, 1)); // 初始化权重
#ifdef DEBUG
    std::cout << "Call WeightedQuickUnion constructor func." << std::endl;
#endif
}

WeightedQuickUnion::~WeightedQuickUnion() {
#ifdef DEBUG
    std::cout << "Call WeightedQuickUnion distructor func." << std::endl;
#endif
}

unsigned int WeightedQuickUnion::getAmount() {
    return mArray.size();
}

bool WeightedQuickUnion::isConnected(unsigned int q, unsigned int p) {
    return getRoot(q) == getRoot(p); //如果节点的root节点相同，则为连通的
}

unsigned int WeightedQuickUnion::getRoot(unsigned int q) {
    while (q != mArray[q]) // 如果节点存的值跟其index相同，即节点的root节点为其本身。
        q = mArray[q];     //否则将索引置为父节点
    return q;
}

void WeightedQuickUnion::interLink(unsigned int q, unsigned int p) {
    unsigned int i = getRoot(q);
    unsigned int j = getRoot(p);
    unsigned int i_weight = mWeightArray[i];
    unsigned int j_weight = mWeightArray[j];
    if (i_weight < j_weight) {
        mArray[i] = j;
        mWeightArray[j] += mWeightArray[i];
    } else {
        mArray[j] = i;
        mWeightArray[i] += mWeightArray[j];
    }
}