#pragma once
#include "MonteCarloSimulation.h"
#include "QuickFind.h"
#include "QuickUnion.h"
#include "VirtualClass.h"
#include "WeightedQuickUnion.h"
#include <iostream>
#include <string>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void initUnionFindModule(py::module &m, std::string module_name, std::string module_intro);