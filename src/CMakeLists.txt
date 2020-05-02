cmake_minimum_required (VERSION 3.6)
project(steamget)

add_executable(steamget steamget.cpp)

add_subdirectory( lib/curlpp )
target_link_libraries( steamget curlpp )
