cmake_minimum_required(VERSION 3.6)
project(steamget VERSION 1.0.0)

include_directories("lib/curlpp/include")

add_executable(steamget steamget.cpp)

