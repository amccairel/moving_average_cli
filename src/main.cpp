#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>

#include "exponential_moving_average.h"
#include "../include/cxxopts.hpp"
#include "../include/ohlc_data.h"
#include "../include/simple_moving_average.h"

// TODO: make reader writer
std::vector<OhlcData> read_csv(const std::string& filename) {
    std::ifstream ifile(filename);
    if (!ifile.is_open()) {
        throw std::runtime_error("Error opening file: " + filename);
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

    return ohlc_data;
};

void write_csv(const std::map<std::string, double>& ma_map, const std::string& filename, const std::string& ma_type, int window) {
    std::ofstream ofile(filename);
    if (!ofile.is_open()) {
        throw std::runtime_error("Error writing to file: " + filename);
    }
    ofile << window << " Day Moving Average" << std::endl;
    ofile << "Date," << ma_type << std::endl;
    for (const auto& [key, value]: ma_map) {
        ofile << key << "," << value << std::endl;
    }

    ofile.close();
}

int main(int argc, char const *argv[]) {
    cxxopts::Options options("moving_average_cli","Moving Average CLI: Calculate moving averages from OHLC data and write to csv.");

    options.add_options()
       ("i,input", "Input CSV file", cxxopts::value<std::string>())
       ("o,output", "Output CSV file", cxxopts::value<std::string>()->default_value("10_day_sma.csv"))
       ("t,type", "Moving average type", cxxopts::value<std::string>()->default_value("SMA"))
       ("w,window", "Window size", cxxopts::value<int>()->default_value("10"))
       ("h,help", "Print help");

    const cxxopts::ParseResult result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    std::string input = result["input"].as<std::string>();
    std::string output = result["output"].as<std::string>();
    std::string type = result["type"].as<std::string>();
    int window = result["window"].as<int>();

    std::vector<OhlcData> ohlc_data;
    try {
        ohlc_data = read_csv(input);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::unique_ptr<MovingAverage> moving_average;
    if (type == "SMA") {
        moving_average = std::make_unique<SimpleMovingAverage>();
    } else if (type == "EMA") {
        moving_average = std::make_unique<ExponentialMovingAverage>();
    } else {
        std::cerr << "Unknown moving average type: " << type << std::endl;
        return 1;
    }

    const std::map<std::string, double> ma_map = moving_average -> calculate(ohlc_data, window);

    write_csv(ma_map, output, type, window);

    return 0;
}