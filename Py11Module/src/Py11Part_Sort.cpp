#include "Py11Part_Sort.h"

// 初始化某一类型的排序函数
template <typename T>
void initSortModuleOfOneType(py::module &m, std::string suffix) {
    py::class_<SortBase<T>, std::shared_ptr<SortBase<T>>>(m, ("SortBase" + suffix).c_str())
        //    .def(py::init<>())
        .def("sort", &SortBase<T>::sort,
             py::arg("array"))
        .def("isSorted", &SortBase<T>::isSorted,
             py::arg("array"),
             py::return_value_policy::copy);

    py::class_<SelectSort<T>, SortBase<T>, std::shared_ptr<SelectSort<T>>>(m, ("SelectSort" + suffix).c_str())
        .def(py::init<>())
        .def("sort", &SelectSort<T>::sort,
             py::arg("array"));

    py::class_<InsertSort<T>, SortBase<T>, std::shared_ptr<InsertSort<T>>>(m, ("InsertSort" + suffix).c_str())
        .def(py::init<>())
        .def("sort", &InsertSort<T>::sort,
             py::arg("array"));
}

py::list inputList(py::list a) {
    a.append(10);
    return a;
}

class Buffer {
public:
    Buffer(py::buffer b) {
        py::buffer_info info = b.request();
        unsigned int size = 0;
        for (unsigned int n = 0; n < info.ndim; ++n) {
            size += info.shape[n];
        }
        if (info.format == py::format_descriptor<int>::format()) {
            for (unsigned int i = 0; i < size; ++i) {
                mIntVec.push_back(*(static_cast<int *>(info.ptr) + i));
            }
        }
    }

    std::vector<int> mIntVec;
};

class Base{
};

class B:public Base {};
class C :public Base{
public:
};

// 将添加到模块中的函数
void initSortModule(py::module &m, std::string module_name, std::string module_intro) {

    // 创建子模块
    py::module_ mm = m.def_submodule(module_name.c_str(), module_intro.c_str());

    // 绑定STL类型
    py::bind_vector<std::vector<int>>(mm, "VectorInt", pybind11::module_local(false));
    py::bind_vector<std::vector<double>>(mm, "VectorDouble", pybind11::module_local(false));
    py::bind_vector<std::vector<float>>(mm, "VectorFloat", pybind11::module_local(false));

    // 子模块绑定
    mm.def("inputList", &inputList);
    initSortModuleOfOneType<double>(mm, "Double");
    initSortModuleOfOneType<int>(mm, "Int");
    initSortModuleOfOneType<float>(mm, "Float");

    py::class_<Buffer>(mm, "Buffer", py::buffer_protocol())
        .def(py::init<py::buffer>());
    // py::implicitly_convertible<std::vector<int>, py::list>;

    py::class_<Base, std::shared_ptr<Base>>(mm, "Base").def(py::init<>());
    py::class_<B, Base, std::shared_ptr<B>>(mm, "B").def(py::init<>());
    py::class_<C, Base, std::shared_ptr<C>>(mm, "C").def(py::init<>());
    mm.def("inputAClass", [](std::shared_ptr<Base>) {});
    mm.def(
        "returnAClass", []() { return new B{}; }, py::return_value_policy::take_ownership);
    mm.def(
        "returnAClass", [](int) { return new C{}; }, py::return_value_policy::take_ownership);
    
}