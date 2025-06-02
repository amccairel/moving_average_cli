//
// Created by Alexander McCairel on 5/18/25.
//
#include "../include/simple_moving_average.h"

std::map<std::string, double> SimpleMovingAverage::calculate(const std::vector<OhlcData>& ohlc_data, const int &window) const {
    std::map<std::string, double> average_map;
    if (window <= 0 || ohlc_data.empty()) {
        return average_map;
    }

    std::vector<double> circular_buffer(window, 0.0);
    double sum = 0;
    int index = 0;

    for (int i = 0; i < ohlc_data.size(); ++i) {
        if (i < window) {
            // run a cumulative average to fill the buffer
            sum += ohlc_data[i].close;
            circular_buffer[index] = ohlc_data[i].close;
            average_map[ohlc_data[i].date] = sum / (i + 1); // cumulative avg -> sum n objects/ n
        } else {
            // buffer is full, utilize fifo properties
            sum -= circular_buffer[index];
            sum += ohlc_data[i].close;
            circular_buffer[index] = ohlc_data[i].close;
            average_map[ohlc_data[i].date] = sum / window;
        }

        // "increase" circular buffer index
        index = (index + 1) % window;
    }

    return average_map;
}
