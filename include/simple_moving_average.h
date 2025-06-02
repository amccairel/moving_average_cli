//
// Created by Alexander McCairel on 5/17/25.
//

#ifndef SIMPLE_MOVING_AVERAGE_H
#define SIMPLE_MOVING_AVERAGE_H

#include "moving_average.h"

class SimpleMovingAverage final : public MovingAverage {
public:
    SimpleMovingAverage() = default;

    [[nodiscard]]
    std::map<std::string, double> calculate(const std::vector<OhlcData>& ohlc_data, const int &window) const override;
};
#endif //SIMPLE_MOVING_AVERAGE_H
