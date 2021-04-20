#pragma once
#include "InsertSort.h"
#include "SelectSort.h"
#include "SortBase.h"
#include <string>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

void initSortModule(py::module &m, std::string module_name, std::string module_intro);