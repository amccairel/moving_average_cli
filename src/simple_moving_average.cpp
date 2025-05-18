//
// Created by Alexander McCairel on 5/18/25.
//
#include "../include/simple_moving_average.h"

std::vector<double> SimpleMovingAverage::calculate() const {
    std::vector<double> result;
    if (window_ == 0 || values_.size() < window_)
        return result;

    result.resize(values_.size(), NAN);  // pad with NaNs

    double sum = 0.0;
    for (size_t i = 0; i < values_.size(); ++i) {
        sum += values_[i];

        if (i >= window_) {
            sum -= values_[i - window_];
        }

        if (i >= window_ - 1) {
            result[i] = sum / window_;
        }
    }

    return result;
}
