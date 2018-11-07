cmake_minimum_required(VERSION 3.12)
project(goFish)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(goFish
    cmake-build-debug/cmake_install.cmake
    cmake-build-debug/CMakeCache.txt
    cmake-build-debug/goFish.cbp
    cmake-build-debug/Makefile
    card.cpp
    card.h
    CMakeLists.txt
    deck.cpp
    deck.h
    main.cpp
    player.cpp
    player.h)
