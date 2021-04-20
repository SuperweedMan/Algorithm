#pragma once

class UnionFindBase {
public:
    virtual bool isConnected(unsigned int, unsigned int) = 0;
    virtual void interLink(unsigned int, unsigned int) = 0;
    virtual unsigned int getAmount() = 0;
    virtual ~UnionFindBase(){};
};