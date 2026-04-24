#pragma once
#include <limits>

namespace CoreLib {
class Statistics
{
public:
    Statistics()
        : sum(0), count(0), max(std::numeric_limits<float>::lowest()),
          min(std::numeric_limits<float>::max())
    {
    }

    inline float GetMean() const
    {
        return count > 0 ? static_cast<float>(sum) / count : 0.0f;
    }
    inline float GetSum() const { return static_cast<float>(sum); }
    inline float GetMax() const { return max; }
    inline float GetMin() const { return min; }
    inline long GetCount() const { return count; }

protected:
    double sum;
    long count;
    float max;
    float min;
};

class StatisticsAlpha : public Statistics
{
public:
    StatisticsAlpha() : Statistics() {}
    inline void AddMeasurement(float measurement)
    {
        if (measurement > max)
        {
            max = measurement;
        }
        if (measurement < min)
        {
            min = measurement;
        }
        sum += measurement;
        count++;
    }
};
} // namespace CoreLib