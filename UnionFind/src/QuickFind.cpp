#include "QuickFind.h"

QuickFind::QuickFind(unsigned int n) {
    pArray.reserve(n);
    for (unsigned int i = 0; i < n; ++i)
        pArray.push_back(i);
#ifdef DEBUG
    std::cout << "Call QuickFind constructor func." << std::endl;
#endif
}

unsigned int QuickFind::getAmount() {
    return pArray.size();
}

bool QuickFind::isConnected(unsigned int p, unsigned q) {
    return pArray[p] == pArray[q];
}

void QuickFind::interLink(unsigned int p, unsigned int q) {
    unsigned int temp = pArray[q];
    unsigned int key = pArray[p];
    for (auto iter = pArray.begin(); iter != pArray.end(); ++iter) {
        if (*iter == temp)
            *iter = key;
    }
}