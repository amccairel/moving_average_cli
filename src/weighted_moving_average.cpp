//
// Created by Alexander McCairel on 6/5/25.
//

#include "weighted_moving_average.h"

std::vector<double> WeightedMovingAverage::calculate(const std::vector<double>& prices, const int& window) const {
    std::vector<double> averages;
    // the denominator for a wma is the triangle number (n * (n + 1)) / 2
    const int denominator = (window * (window + 1)) / 2;

    double numerator = 0.0;
    double total = 0.0;

    for (int i = 0; i < window; i++) {
        total += prices[i];
        numerator += (i + 1) * prices[i]; // weight most current data the most
    }

    // fill first values with a cumulative average
    double sum = 0.0;
    for (int i = 0; i < window -1; i++) {
        sum += prices[i];
        averages.push_back(sum / (i + 1));
    }

    // now add the first wma, obtained from the first for loop
    averages.push_back(numerator / denominator);

    // rolling wma
    for (int i = window; i < prices.size(); i++) {
        const double new_price = prices[i];
        const double old_price = prices[i - window];

        // update the total
        total = total + new_price - old_price;

        // update the numerator
        numerator = numerator + (window * new_price) - total;

        averages.push_back(numerator / denominator);
    }

    return averages;
}