//
// Created by Alexander McCairel on 6/5/25.
//

#ifndef WEIGHTED_MOVING_AVERAGE_H
#define WEIGHTED_MOVING_AVERAGE_H

#include "moving_average.h"

class WeightedMovingAverage final : public MovingAverage {
public:
    WeightedMovingAverage() = default;

    [[nodiscard]]
    std::vector<double> calculate(const std::vector<double>& data, const int& window) const override;
};
#endif //WEIGHTED_MOVING_AVERAGE_H
