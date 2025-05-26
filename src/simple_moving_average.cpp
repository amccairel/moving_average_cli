//
// Created by Alexander McCairel on 5/18/25.
//
#include "../include/simple_moving_average.h"

std::map<std::string, double> SimpleMovingAverage::calculate(const std::vector<OhlcData>& ohlc_data, int window) const {
    std::map<std::string, double> average_map;
    if (window == 0 || ohlc_data.size() < window) {
        return average_map;
    }

    // pad with NaNs
    for (int i = 0; i < window - 1; ++i) {
        const OhlcData& ohlc_entry = ohlc_data[i];
        average_map[ohlc_entry.date] = NAN;
    }

    double sum = 0.0;
    for (int i = 0; i < ohlc_data.size(); ++i) {
        const OhlcData& ohlc_entry = ohlc_data[i];
        sum += ohlc_entry.close;

        if (i >= window) {
            sum -= ohlc_data[i - window].close;
        }

        if (i >= window - 1) {
            average_map[ohlc_entry.date] = sum / window;
        }
    }

    return average_map;
}
