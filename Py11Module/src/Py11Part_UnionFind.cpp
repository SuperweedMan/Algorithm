#include "Py11Part_UnionFind.h"

// namespace py = pybind11;

void initUnionFindModule(py::module &m, std::string module_name, std::string module_intro){

    py::module_ mm = m.def_submodule(module_name.c_str(), module_intro.c_str());
    py::class_<UnionFindBase, std::shared_ptr<UnionFindBase>>(mm, "UnionFindBase")
        // .def(py::init<>())
        .def("isConnected", &UnionFindBase::isConnected,
             py::arg("ElementIdx_i"), py::arg("ElementIdx_j"),
             py::return_value_policy::copy)
        .def("interLink", &UnionFindBase::interLink,
             py::arg("ElementIdx_i"), py::arg("ElementIdx_j"),
             py::return_value_policy::copy);

    py::class_<QuickFind, UnionFindBase, std::shared_ptr<QuickFind> >(mm, "QuickFind")
        .def(py::init<unsigned int>(), py::arg("NumOfElement"))
        .def("isConnected", &QuickFind::isConnected,
             py::arg("ElementIdx_i"), py::arg("ElementIdx_j"),
             py::return_value_policy::copy)
        .def("interLink", &QuickFind::interLink,
             py::arg("ElementIdx_i"), py::arg("ElementIdx_j"),
             py::return_value_policy::copy)
        .def("__repr__", [](const QuickFind &a) { return "UnionFind.QucikFind."; });

    py::class_<QuickUnion, UnionFindBase, std::shared_ptr<QuickUnion> >(mm, "QuickUnion")
        .def(py::init<unsigned int>(), py::arg("NumOfElement"))
        .def("isConnected", &QuickUnion::isConnected,
             py::arg("ElementIdx_i"), py::arg("ElementIdx_j"),
             py::return_value_policy::copy)
        .def("interLink", &QuickUnion::interLink,
             py::arg("ElementIdx_i"), py::arg("ElementIdx_j"),
             py::return_value_policy::copy)
        .def("__repr__", [](const QuickUnion &a) { return "UnionFind.QucikUnion."; });

    py::class_<WeightedQuickUnion, UnionFindBase, std::shared_ptr<WeightedQuickUnion> >(mm, "WeightedQuickUnion")
        .def(py::init<unsigned int>(), py::arg("NumOfElement"))
        .def("isConnected", &WeightedQuickUnion::isConnected,
             py::arg("ElementIdx_i"), py::arg("ElementIdx_j"),
             py::return_value_policy::copy)
        .def("interLink", &WeightedQuickUnion::interLink,
             py::arg("ElementIdx_i"), py::arg("ElementIdx_j"),
             py::return_value_policy::copy)
        .def("__repr__", [](const WeightedQuickUnion &a) { return "UnionFind.WeightedQuickUnion."; });

    py::class_<MonteCarloSimulation>(mm, "MonteCarloSimulation")
        .def(py::init<unsigned int>(), py::arg("NumOfElement"))
        .def(py::init<std::shared_ptr<UnionFindBase>>(), py::arg("SharedPtrForUnionFindObj"))
        .def("step", &MonteCarloSimulation::step)
        .def("run", &MonteCarloSimulation::run, py::return_value_policy::automatic);
}