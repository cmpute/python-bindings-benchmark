// This file contains all the C++ implementations

#include <vector>
#include <algorithm>

class SortedVector
{
protected:
    std::vector<float> _data;
public:
    SortedVector(const std::vector<float> &data) : _data(data) {
        std::sort(_data.begin(), _data.end());
    }
    inline size_t size() const { return _data.size(); }
    inline const std::vector<float>& data() const { return _data; }

    std::pair<float, float> minmax() { return std::make_pair(_data.front(), _data.back()); }
};

class AccumulatedVector : public SortedVector
{
protected:
    std::vector<float> _accumulated;
public:
    AccumulatedVector(const std::vector<float> &data) : AccumulatedVector(data, 0) {}
    AccumulatedVector(const std::vector<float> &data, float init) : SortedVector(data) {
        _accumulated.reserve(_data.size());
        float acc = 0;
        for (int i = 0; i < _data.size(); i++)
        {
            _accumulated.push_back(acc);
            acc += _data[i];
        }
    }
    
    inline const std::vector<float>& accumulated() const { return _accumulated; }
};

size_t find_accumulated(const SortedVector &vec, float target)
{
    if (target < 0)
        return 0;

    size_t sum = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (sum <= target && sum + vec.data()[i] > target)
            return i+1;
    }

    return vec.size();
}

size_t find_accumulated(const AccumulatedVector &vec, float target)
{
    std::lower_bound(vec.accumulated().begin(), vec.accumulated().end(), target);
}

float sum(const SortedVector &vec)
{
    size_t sum = 0;
    for (auto f : vec.data()) sum += f;
    return sum;
}

float sum(const AccumulatedVector &vec)
{
    return vec.accumulated().back();
}
