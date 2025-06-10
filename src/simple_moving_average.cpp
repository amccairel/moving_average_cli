//
// Created by Alexander McCairel on 5/18/25.
//
#include "simple_moving_average.h"

std::vector<double> SimpleMovingAverage::calculate(const std::vector<double>& prices, const int& window) const {
    std::vector<double> averages;
    if (window <= 0 || prices.empty()) {
        return averages;
    }

    std::vector<double> circular_buffer(window, 0.0);
    double sum = 0;
    int index = 0;

    for (int i = 0; i < prices.size(); ++i) {
        if (i < window) {
            circular_buffer[index] = prices[i]; // fill the buffer
            sum += prices[i];
            averages.push_back(sum / (i + 1)); // use a cumulative avg for first avgs
        } else {
            // buffer is full, utilize fifo properties
            sum -= circular_buffer[index];
            sum += prices[i];
            circular_buffer[index] = prices[i];
            averages.push_back(sum / window);
        }

        // "increase" circular buffer index
        index = (index + 1) % window;
    }

    return averages;
}
