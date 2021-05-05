cmake_minimum_required(VERSION 3.19)
project(linear_regression)

set(CMAKE_CXX_STANDARD 14)

add_executable(linear_regression main.cpp Data.cpp Data.h LinearRegression.cpp LinearRegression.h)
