#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>
#include <ranges>

#include "exponential_moving_average.h"
#include "cxxopts.hpp"
#include "ohlc_data.h"
#include "simple_moving_average.h"
#include "weighted_moving_average.h"

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

void write_ma_csv(const std::vector<std::string>& dates, const std::map<std::string, std::vector<double>>& ma_map, const std::string& filename) {
    std::ofstream o_file(filename);
    if (!o_file.is_open()) {
        throw std::runtime_error("Error writing to file: " + filename);
    }

    o_file << "Date";
    for (const std::string& ma_label: ma_map | std::views::keys) {
        o_file << "," << ma_label;
    }
    o_file << std::endl;

    for (int i = 0; i < dates.size(); i++) {
        o_file << dates[i];
        for (const std::vector<double>& averages: ma_map | std::views::values) {
            o_file << "," << averages[i]; // averages.length == dates.length
        }
        o_file << std::endl;
    }

    o_file.close();
}

int main(int argc, char const *argv[]) {
    cxxopts::Options options("moving_average_cli","Moving Average CLI: Calculate moving averages from OHLC data and write to csv.");

    options.add_options()
       ("i,input", "Input CSV file", cxxopts::value<std::string>())
       ("o,output", "Output CSV file", cxxopts::value<std::string>()->default_value("10_day_sma.csv"))
       ("t,type", "Moving average type(sma, ema, etc.)", cxxopts::value<std::vector<std::string>>()->default_value({"sma"}))
       ("w,window", "Window size", cxxopts::value<std::vector<int>>()->default_value({10}))
       ("h,help", "Print help");

    const cxxopts::ParseResult result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    const std::string input = result["input"].as<std::string>();
    const std::string output = result["output"].as<std::string>();
    const std::vector<std::string> types = result["type"].as<std::vector<std::string>>();
    const std::vector<int> windows = result["window"].as<std::vector<int>>();

    if (types.size() != windows.size()) {
        std::cerr << "Error: The number of --type and --window arguments must match." << std::endl;
        return 1;
    }

    std::vector<OhlcData> ohlc_data;
    try {
        ohlc_data = read_csv(input);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::vector<std::string> dates;
    std::vector<double> close_prices;
    for (const OhlcData& ohlc_entry: ohlc_data) {
        dates.push_back(ohlc_entry.date);
        close_prices.push_back(ohlc_entry.close);
    }

    std::map<std::string, std::vector<double>> ma_map;
    for (int i = 0; i < types.size(); i++) {
        std::unique_ptr<MovingAverage> moving_average;
        if (types[i] == "sma") {
            moving_average = std::make_unique<SimpleMovingAverage>();
        } else if (types[i] == "ema") {
            moving_average = std::make_unique<ExponentialMovingAverage>();
        } else if (types[i] == "wma") {
            moving_average = std::make_unique<WeightedMovingAverage>();
        } else {
            std::cerr << "Unknown moving average type: " << types[i] << std::endl;
            return 1;
        }

        std::string ma_label = types[i] + "_" + std::to_string(windows[i]);
        ma_map[ma_label] = moving_average -> calculate(close_prices, windows[i]);
    }

    write_ma_csv(dates, ma_map, output);

    return 0;
}