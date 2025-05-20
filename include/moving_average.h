//
// Created by Alexander McCairel on 5/17/25.
//

#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <vector>
#include <map>
#include "ohlc_data.h"

class MovingAverage {
public:
    virtual ~MovingAverage() = default;

    [[nodiscard]]
    virtual std::map<std::string, double> calculate(const std::vector<OhlcData>& ohlc_data, size_t window) const = 0;
};
#endif //MOVING_AVERAGE_H
