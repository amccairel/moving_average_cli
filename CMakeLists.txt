cmake_minimum_required(VERSION 3.31)
project(moving_average_cli)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(moving_average_cli src/main.cpp
        src/simple_moving_average.cpp
        src/exponential_moving_average.cpp
        src/cumulative_moving_average.cpp
)
