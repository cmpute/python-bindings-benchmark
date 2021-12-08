from libcpp.vector cimport vector
from cython_base cimport SortedVector, CySortedVector

cdef extern from "impl.hpp":
    cdef cppclass AccumulatedVector(SortedVector):
        AccumulatedVector(const vector[float] &)
    cdef float csum "sum" (const AccumulatedVector&)

cdef class CyAccumulatedVector(CySortedVector):
    pass
