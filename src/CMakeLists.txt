cmake_minimum_required (VERSION 3.6)
project(steamget)

add_executable(steamget steamget.cpp)

target_link_libraries( steamget /home/elal/Projects/steamget/lib/steamsdk/libsteam_api.so )
