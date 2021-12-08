#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "impl.hpp"

namespace py = pybind11;

PYBIND11_MODULE(pybind11_derived, m) {
    py::class_<AccumulatedVector, SortedVector>(m, "PbAccumulatedVector")
        .def(py::init<const std::vector<float> &>())
        .def(py::init<const std::vector<float> &, float>());

    m.def("sum", static_cast<float (*)(const AccumulatedVector&)>(sum));
}
