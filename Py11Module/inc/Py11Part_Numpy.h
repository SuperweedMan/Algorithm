#pragma once
#include <string>
#include <vector>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

void initNumPyModule(py::module &m, std::string module_name, std::string module_intro);