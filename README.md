# 📈 Moving Average CLI – Simple Moving Average Calculator in C++

This is a lightweight command-line application written in modern C++20 to calculate **Simple Moving Averages (SMA)** from OHLC (Open, High, Low, Close) data. The app reads a CSV file generated via [yfinance](https://github.com/ranaroussi/yfinance) and outputs an annotated CSV with SMA values, suitable for plotting or further analysis.

---

## 🔧 Features

- Reads historical stock price data from CSV
- Computes n-day simple moving averages
- Outputs a clean CSV with dates, close prices, and SMA values
- Designed with modular, modern C++ (RAII, STL, separation of concerns)
- Easily extendable for other indicators (EMA, RSI, MACD, etc.)

---

## 📂 Project Structure
moving-average-cli/
├── include/ # Header files (interfaces)
├── src/ # Source code
├── output/ # Output with SMA annotations
├── CMakeLists.txt # Build configuration
└── README.md

---

## 🚀 Getting Started

### 🛠️ Requirements

- C++20 compiler (GCC, Clang, MSVC)
- CMake 3.10+

### 📦 Build & Run

```bash
# Clone the repo
git clone https://github.com/YOUR_USERNAME/moving_average_cli.git
cd moving_average_cli

# Create build directory
mkdir build && cd build
cmake ..
make

# Run the app
./moving_average_cli
```

