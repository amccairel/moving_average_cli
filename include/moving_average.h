//
// Created by Alexander McCairel on 5/17/25.
//

#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <vector>

class MovingAverage {
public:
    MovingAverage(const std::vector<double>& values, size_t window): values_(values), window_(window) {};
    virtual ~MovingAverage() = default;
    virtual std::vector<double> calculate() const = 0;
protected:
    std::vector<double> values_;
    size_t window_;
};
#endif //MOVING_AVERAGE_H
