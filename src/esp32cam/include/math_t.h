#include "common_includes.h"

namespace math
{
    template <class T>
    T convert(T x, T in_min, T in_max, T out_min, T out_max)
    {
        T result = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        if (result < 0)
        {
            return 0;
        }
        else if (result > 100)
        {
            return 100;
        }
        return result;
    }
};