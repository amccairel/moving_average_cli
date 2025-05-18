cmake_minimum_required(VERSION 3.31)
project(moving_average_cli)

set(CMAKE_CXX_STANDARD 20)

add_executable(moving_average_cli src/main.cpp
        include/ohlc_data.h
        include/simple_moving_average.h
        include/moving_average.h
        include/exponential_moving_average.h
        src/simple_moving_average.cpp
)
