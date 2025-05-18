//
// Created by Alexander McCairel on 5/17/25.
//

#ifndef SIMPLE_MOVING_AVERAGE_H
#define SIMPLE_MOVING_AVERAGE_H
#include "moving_average.h"
#include <vector>

class SimpleMovingAverage: public MovingAverage {
public:
    explicit SimpleMovingAverage(const std::vector<double>& prices, const size_t& window): MovingAverage(prices, window) {};
    std::vector<double> calculate() const override;
};
#endif //SIMPLE_MOVING_AVERAGE_H
