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
    std::map<std::string, double> calculate(const std::vector<OhlcData> &ohlc_data, const int &window) const override;
};
#endif //CUMULATIVE_MOVING_AVERAGE_H
