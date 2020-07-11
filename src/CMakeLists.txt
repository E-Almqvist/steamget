cmake_minimum_required(VERSION 3.6)
project(steamget VERSION 1.0.0)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json GIT_REPOSITORY https://github.com/nlohmann/json.git)
FetchContent_MakeAvailable(json)

add_executable(steamget steamget.cpp)

target_link_libraries(steamget PRIVATE cpr::cpr)
target_link_libraries(steamget PRIVATE nlohmann_json::nlohmann_json)
