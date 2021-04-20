// #include <pybind11/iostream.h>
// #include <pybind11/pybind11.h>
// #include <pybind11/stl_bind.h>
// #include <iostream>

// namespace py = pybind11;

// void print2Test() {
//     std::cout << "print2 successfully." << std::endl;
// }

// PYBIND11_MODULE(testModule, m) {

//     m.doc() = "My test module.";

//     m.def("print2Test", []() {
//         py::scoped_ostream_redirect stream(
//             std::cout,                                // std::ostream&
//             py::module_::import("sys").attr("stdout") // Python output
//         );
//         print2Test();
//     });
// }