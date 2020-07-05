cmake_minimum_required(VERSION 3.6)
project(steamget VERSION 1.0.0)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git)
FetchContent_MakeAvailable(cpr)

add_executable(steamget steamget.cpp)

target_link_libraries(steamget PRIVATE cpr::cpr)
