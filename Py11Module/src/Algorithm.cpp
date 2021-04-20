#include "Py11Part_Sort.h"
#include "Py11Part_UnionFind.h"
#include "Py11Part_Numpy.h"
#include <iostream>
#include <pybind11/iostream.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;



void printTest() {
    std::cout << "print successfully." << std::endl;
}



// Py11Module的接口文件
PYBIND11_MODULE(Algorithm, m) {

    m.doc() = "My pybind11 Algorithm module.";

    // Array
    initNumPyModule(m, "Array", "A module of mArray");

    // 连通域算法
    initUnionFindModule(m, "UnionFind", "A module of union find.");

    // 排序算法
    initSortModule(m, "Sort", "A module of sort algorithm.");

    m.def("printTest", []() {
        py::scoped_ostream_redirect stream(
            std::cout,                                // std::ostream&
            py::module_::import("sys").attr("stdout") // Python output
        );
        printTest();
    });


}
