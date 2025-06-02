//
// Created by Alexander McCairel on 5/25/25.
//
#include "../include/exponential_moving_average.h"

std::map<std::string, double> ExponentialMovingAverage::calculate(const std::vector<OhlcData> &ohlc_data, const int &window) const {
    std::map<std::string, double> ema_map;
    const double alpha = 2.0 / (window + 1);

    double last_ema = ohlc_data[0].close;
    for (auto& ohlc_entry : ohlc_data) {
        double new_ema = alpha * (ohlc_entry.close - last_ema) + last_ema;
        ema_map[ohlc_entry.date] = new_ema;
        last_ema = new_ema;
    }

    return ema_map;
}