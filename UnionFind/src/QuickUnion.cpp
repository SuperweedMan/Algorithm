#include "QuickUnion.h"

QuickUnion::QuickUnion(unsigned int n) {
    mArray.reserve(n);
    for (unsigned int i = 0; i < n; ++i) //初始化，使每个节点的root为自己
        mArray.push_back(i);
#ifdef DEBUG
    std::cout << "Call QuickUnion constructor func." << std::endl;
#endif
}

QuickUnion::~QuickUnion() {
#ifdef DEBUG
    std::cout << "Call QuickUnion distructor func." << std::endl;
#endif
}

unsigned int QuickUnion::getAmount() {
    return mArray.size();
}

bool QuickUnion::isConnected(unsigned int q, unsigned int p) {
    return getRoot(q) == getRoot(p);
}

void QuickUnion::interLink(unsigned int q, unsigned int p) {
    // 将后者的根节点设为前者
    unsigned int i = getRoot(q);
    unsigned int j = getRoot(p);
    mArray[i] = j;
}

unsigned int QuickUnion::getRoot(unsigned int p) {
    while (p != mArray[p])
        p = mArray[p];
    return p;
}