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
    std::vector<double> calculate(const std::vector<double>& prices, const int &window) const override;
};
#endif //EXPONENTIAL_MOVING_AVERAGE_H
