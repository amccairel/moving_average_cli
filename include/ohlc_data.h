//
// Created by Alexander McCairel on 5/17/25.
//

#ifndef OHLC_DATA_H
#define OHLC_DATA_H

#include <chrono>

struct OhlcData {
    std::string date;
    double open;
    double high;
    double low;
    double close;
    long volume;
    double dividends;
    double stock_splits;
};
#endif //OHLC_DATA_H
