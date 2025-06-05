//
// Created by Alexander McCairel on 5/28/25.
//

#ifndef CUMULATIVE_MOVING_AVERAGE_H
#define CUMULATIVE_MOVING_AVERAGE_H

#include "moving_average.h"

class CumulativeMovingAverage final : public MovingAverage {
public:
    CumulativeMovingAverage() = default;

    [[nodiscard]]
    std::vector<double> calculate(const std::vector<double>& prices, const int& window) const override;
};
#endif //CUMULATIVE_MOVING_AVERAGE_H
