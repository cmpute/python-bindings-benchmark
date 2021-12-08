from cython.operator cimport dereference as deref

cdef class CySortedVector:
    def __cinit__(self, data=None):
        cdef vector[float] cdata

        if type(self) is CySortedVector:
            if data is not None:
                cdata = data
            self._ptr = new SortedVector(cdata)

    def __dealloc__(self):
        if type(self) is CySortedVector:
            del self._ptr

def sum(CySortedVector vec):
    return csum(deref(vec._ptr))
