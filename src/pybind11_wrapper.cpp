#include "Crockford32.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(crockford32, m) {
  m.doc() = "crockford base32 encoding implementation";

  m.def("encode", &encode, "function for encoding data", py::arg("input_chars"), py::arg("checksum") = false);
  m.def("decode", &decode, "function for decoding data", py::arg("input_chars"), py::arg("checksum") = false);
}
