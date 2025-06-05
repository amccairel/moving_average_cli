//
// Created by Alexander McCairel on 5/25/25.
//
#include "../include/exponential_moving_average.h"

std::vector<double> ExponentialMovingAverage::calculate(const std::vector<double>& prices, const int& window) const {
    std::vector<double> averages;
    const double alpha = 2.0 / (window + 1);

    double last_ema = prices[0];
    for (double price : prices) {
        double new_ema = alpha * (price - last_ema) + last_ema;
        averages.push_back(new_ema);
        last_ema = new_ema;
    }

    return averages;
}