#include "Py11Part_Numpy.h"
#ifdef DEBUG
#include <iostream>
#endif

class Array {
    virtual std::string type() = 0;
};

template <typename T>
class SubArray : public Array {
public:
    SubArray(std::vector<T> array, std::string type_name) {
#ifdef DEBUG
        py::print("Call Constructor of class < SubArray<*> >.");
#endif
        mArray = std::move(array);
        mType = type_name;
    }
    ~SubArray() {
#ifdef DEBUG
        py::print("Call Distructor of class < SubArray<*> >.");
#endif
    }
    std::string type() { return mType; }

private:
    std::vector<T> mArray;
    std::string mType;
};

template <typename T>
void defineSubArray(py::module &m, std::string type_name) {
    m.def(
        "array", [type_name](py::array_t<T> array) {
            std::vector<T> temp;
            for (auto i = array.begin(); i != array.end(); ++i) {
                temp.push_back(py::cast<T>(*i));
            }
            std::shared_ptr<SubArray<T>> ptr = std::make_shared<SubArray<T>>(temp, type_name);
            return ptr;
        });
}

template <typename T>
void declareSubArray(py::module &m, std::string s) {
    py::class_<SubArray<T>, Array, std::shared_ptr<SubArray<T>>>(m, s.c_str())
        // .def(py::init([](std::vector<T> array) {
        //     py::print("in init");
        //     return std::make_shared<SubArray<T>>(array);
        // }))
        .def(py::init<std::vector<T>, std::string>())
        .def("type", &SubArray<T>::type);
}


void initNumPyModule(py::module &m, std::string module_name, std::string module_intro) {

    // 创建子模块
    py::module_ mm = m.def_submodule(module_name.c_str(), module_intro.c_str());
    py::class_<Array, std::shared_ptr<Array>>(mm, "ArrayBase");

    declareSubArray<int>(mm, "IntArray");
    // py::class_<SubArray<double>, Array, std::shared_ptr<SubArray<double>>>(mm, "DoubleArray")
    // .def(py::init([](std::vector<double> array) { return std::make_shared<SubArray<double>>(array); }));
    declareSubArray<double>(mm, "DoubleArray");
    defineSubArray<int>(mm, "IntArray");
    defineSubArray<double>(mm, "DoubleArray");
}