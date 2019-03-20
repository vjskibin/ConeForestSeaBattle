cmake_minimum_required(VERSION 3.13)
project(ConeForestSeaBattle)

set(CMAKE_CXX_STANDARD 14)

add_executable(ConeForestSeaBattle cpp/main.cpp cpp/Battle.cpp model/Battle.h cpp/Player.cpp model/Player.h cpp/AI.cpp model/AI.h cpp/UI.cpp model/UI.h cpp/Keyboard.cpp model/Keyboard.h cpp/Ship.cpp model/Ship.h)