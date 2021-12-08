from libcpp.vector cimport vector

cdef extern from "impl.hpp":
    cdef cppclass SortedVector:
        SortedVector(const vector[float] &)
    cdef float csum "sum" (const SortedVector&)

cdef class CySortedVector: # wrapped sorted vector
    cdef SortedVector *_ptr
