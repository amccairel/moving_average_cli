#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "../include/ohlc_data.h"
#include "../include/simple_moving_average.h"

int main(int argc, char const *argv[]) {
    // TODO: change to command line argument
    std::ifstream ifile("history.csv");
    if (!ifile.is_open()) {
        // TODO: print file too
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<OhlcData> ohlc_data;
    std::getline(ifile, line); // skip the header

    while (std::getline(ifile, line)) {
        std::stringstream ss(line);
        std::string cell;
        OhlcData ohlc_entry;

        std::getline(ss, ohlc_entry.date, ',');
        std::getline(ss, cell, ',');
        ohlc_entry.open = std::stod(cell);
        std::getline(ss, cell, ',');
        ohlc_entry.high = std::stod(cell);
        std::getline(ss, cell, ',');
        ohlc_entry.low = std::stod(cell);
        std::getline(ss, cell, ',');
        ohlc_entry.close = std::stod(cell);
        std::getline(ss, cell, ',');
        ohlc_entry.volume = std::stol(cell);
        std::getline(ss, cell, ',');
        ohlc_entry.stock_splits = std::stod(cell);

        ohlc_data.push_back(ohlc_entry);
    }

    ifile.close();

    for (const auto& ohlc_entry : ohlc_data) {
        std::cout << ohlc_entry.date << " Open: " << ohlc_entry. open << " High: "<< ohlc_entry.high <<
            " Low: " << ohlc_entry.low << " Close: " << ohlc_entry.close << " Volume: "<< ohlc_entry.volume << std::endl;
    }

    std::vector<double> close_prices;
    close_prices.reserve(ohlc_data.size());
    for (const auto& ohlc_entry : ohlc_data) {
        close_prices.push_back(ohlc_entry.close);
    }

    SimpleMovingAverage simple_moving_average(close_prices, 10);
    for (std::vector<double> ten_day_averages = simple_moving_average.calculate(); const double& a: ten_day_averages) {
        std::cout << "Ten day average: " << a << std::endl;
    }
    return 0;
}