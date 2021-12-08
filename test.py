import timeit, random

# import test
from cython_base import CySortedVector, sum as cy_sum
from cython_derived import CyAccumulatedVector, sum as cy_sum2
from pybind11_base import PbSortedVector, sum as pb_sum
from pybind11_derived import PbAccumulatedVector, sum as pb_sum2

# test once
data = [random.random() * 10 for _ in range(1000)]
sum_results = [
    cy_sum(CySortedVector(data)),
    cy_sum(CyAccumulatedVector(data)),
    cy_sum2(CyAccumulatedVector(data)),
    pb_sum(PbSortedVector(data)),
    pb_sum2(PbAccumulatedVector(data)),
    pb_sum2(PbAccumulatedVector(data))
]
for r in sum_results[1:]:
    print(r, sum_results[0])
    assert(r == sum_results[0])
print("check passed.")

# benchmark
print("Cython sum (SortedVector)", timeit.timeit('cy_sum(CySortedVector(data))', globals=globals(), number=10000))
print("Cython sum (AccumulatedVector)", timeit.timeit('cy_sum2(CyAccumulatedVector(data))', globals=globals(), number=10000))
print("Pybind11 sum (SortedVector)", timeit.timeit('pb_sum(PbSortedVector(data))', globals=globals(), number=10000))
print("Pybind11 sum (AccumulatedVector)", timeit.timeit('pb_sum2(PbAccumulatedVector(data))', globals=globals(), number=10000))
