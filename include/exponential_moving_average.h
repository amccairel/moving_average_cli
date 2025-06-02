//
// Created by Alexander McCairel on 5/17/25.
//

#ifndef EXPONENTIAL_MOVING_AVERAGE_H
#define EXPONENTIAL_MOVING_AVERAGE_H
#include "moving_average.h"

class ExponentialMovingAverage final : public MovingAverage {
public:
    ExponentialMovingAverage() = default;

    [[nodiscard]]
    std::map<std::string, double> calculate(const std::vector<OhlcData> &ohlc_data, const int &window) const override;
};
#endif //EXPONENTIAL_MOVING_AVERAGE_H
