#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "../include/ohlc_data.h"

int main(int argc, char const *argv[]) {
    std::ifstream ifile("history.csv");
    if (!ifile.is_open()) {
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
        ohlc_entry.volume = std::stod(cell);
        std::getline(ss, cell, ',');
        ohlc_entry.volume = std::stod(cell);
        std::getline(ss, cell, ',');
        ohlc_entry.stock_splits = std::stod(cell);

        ohlc_data.push_back(ohlc_entry);
    }

    ifile.close();

    for (const auto& ohlc_entry : ohlc_data) {
        std::cout << ohlc_entry.date << " Open: " << ohlc_entry. open << " High: "<< ohlc_entry.high <<
            " Low: " << ohlc_entry.low << " Close: " << ohlc_entry.close << " Volume: "<< ohlc_entry.volume << std::endl;
    }
    return 0;
}