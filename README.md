# Moving Average CLI

A high-performance command-line application written in C++ for processing historical stock price data (Open High Low Close format) and computing various types of moving averages. Designed with modularity and extensibility in mind, this project supports flexible user input, multiple moving average types, and future enhancements like terminal indicators.

---

## 🚀 Features

- ⚙️ **Flexible CLI Configuration**: Use `cxxopts` to specify input/output files, window sizes, and moving average types.
- 📈 **Supports Multiple Moving Averages**:
    - Simple Moving Average (SMA)
    - Exponential Moving Average (EMA)
    - Additional indicators in progress 
- 🗃️ **Clean CSV I/O**: Read and write stock data in standard CSV format for easy interoperability.
- 🧠 **Extensible Design**: Add new technical indicators with minimal changes to core logic.
---

## 🛠️ Tech Stack

- **C++20**: Core language
- **cxxopts**: Command-line argument parsing
- **CMake**: Build system
- **CSV**: Input/output format

---

## 📦 Usage

### Compile the app:

```bash
mkdir build && cd build
cmake ..
make
```
### Run the CLI tool:

```bash
./moving_average_cli --input path/to/stock-history.csv --output path/to/output.csv --type ema --window 12
```

### Example Input (CSV)
```csv
Date,Open,High,Low,Close,Volume
2024-01-01,100,105,95,102,1000000
2024-01-02,102,107,98,104,1200000
```

### Example Output
```csv
Date,SMA
2024-01-01,102
2024-01-02,104
```

## Contributing
Suggestions, pull requests, and bug reports are welcome.

## License
MIT License