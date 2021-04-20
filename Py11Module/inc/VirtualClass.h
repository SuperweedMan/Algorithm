#pragma once
#include "UnoinFindBase.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

class PyUnionFindBase : public UnionFindBase{
    public:
    bool isConnected(unsigned int i, unsigned int j) override {
        PYBIND11_OVERRIDE_PURE(bool, UnionFindBase, isConnected, i, j);
    };
    void interLink(unsigned int i, unsigned int j) override{
        PYBIND11_OVERRIDE_PURE(void, UnionFindBase, interLink, i, j);
    };
    unsigned int getAmount() override {
        PYBIND11_OVERRIDE_PURE(unsigned int, UnionFindBase, getAmount);
    };
};