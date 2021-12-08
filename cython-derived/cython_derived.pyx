from cython.operator cimport dereference as deref

cdef class CyAccumulatedVector:
    def __cinit__(self, data=None):
        cdef vector[float] cdata

        if type(self) is CyAccumulatedVector:
            if data is not None:
                cdata = data
            self._ptr = new AccumulatedVector(cdata)

    def __dealloc__(self):
        if type(self) is CyAccumulatedVector:
            del self._ptr

def sum(CyAccumulatedVector vec):
    return csum(deref(<AccumulatedVector*>(vec._ptr)))
