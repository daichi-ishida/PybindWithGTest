#include "print_array_1d.h"
#include "mycuda.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(example_cuda_driver, m)
{
    m.doc() = "my test module";
    m.def("print_array_1d", &print_array_1d<int32_t>, "");
    m.def("print_array_1d", &print_array_1d<double>, "");

    py::class_<cuda_driver::MyCuda>(m, "MyCuda")
            .def(py::init<>())
            .def("add_arrays_int", &cuda_driver::MyCuda::add_arrays_int)
            .def("add_arrays_float", &cuda_driver::MyCuda::add_arrays_float);
}