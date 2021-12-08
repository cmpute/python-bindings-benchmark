#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "impl.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pybind11_base, m) {
    py::class_<SortedVector>(m, "PbSortedVector")
        .def(py::init<const std::vector<float> &>())
        .def_property_readonly("size", &SortedVector::size);

    m.def("sum", static_cast<float (*)(const SortedVector&)>(sum));
}
