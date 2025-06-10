# Moving Average CLI

A high-performance command-line application written in C++ for processing historical stock price data (Open High Low Close format) and computing various types of moving averages. Designed with modularity and extensibility in mind, this project supports flexible user input, multiple moving average types, and future enhancements like terminal indicators.

---

## 🚀 Features

- ⚙️ **Flexible CLI Configuration**: Use `cxxopts` to specify input/output files, window sizes, and moving average types.
- 📈 **Supports Multiple Moving Averages**:
    - Simple Moving Average (SMA)
    - Exponential Moving Average (EMA)
    - Weighted Moving Average (EMA)
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
./moving_average_cli --input path/to/stock-history.csv --output path/to/output.csv --type ema --window 12 --type ema --window 26
```
Or you can use shorthand notation:
```bash
./moving_average_cli -i path/to/stock-history.csv -o path/to/output.csv -t ema -w 12 -t ema -w 26 -t sma -w 10 -t sma -w 20
```

### Example Input (CSV)
```csv
Date,Open,High,Low,Close,Volume,Dividends,Stock Splits
2024-05-17 00:00:00-04:00,188.62783545187153,189.92178705781208,188.29936976198016,188.9861602783203,41282900,0.0,0.0
2024-05-20 00:00:00-04:00,188.44869465688268,191.02663488992152,188.1301769262196,190.15072631835938,44361300,0.0,0.0
2024-05-21 00:00:00-04:00,190.20049107683238,191.83285642957057,190.03128423275254,191.4546356201172,42309400,0.0,0.0
2024-05-22 00:00:00-04:00,191.37501623979523,191.92245910983817,189.38432593982932,190.01138305664062,34648500,0.0,0.0
2024-05-23 00:00:00-04:00,190.09099161364105,190.11090276702717,185.76124979940406,186.0100860595703,51005900,0.0,0.0
2024-05-24 00:00:00-04:00,187.94106857836448,189.6928704821682,187.16468542966413,189.0956573486328,36294600,0.0,0.0
```

### Example Output
```csv
Date,ema_12,ema_26,sma_10,sma_20
2024-05-17 00:00:00-04:00,188.986,188.986,188.986,188.986
2024-05-20 00:00:00-04:00,189.165,189.072,189.568,189.568
2024-05-21 00:00:00-04:00,189.518,189.249,190.197,190.197
2024-05-22 00:00:00-04:00,189.594,189.305,190.151,190.151
2024-05-23 00:00:00-04:00,189.042,189.061,189.323,189.323
2024-05-24 00:00:00-04:00,189.05,189.064,189.285,189.285
```

## Contributing
Suggestions, pull requests, and bug reports are welcome.

## License
MIT License