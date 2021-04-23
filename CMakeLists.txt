cmake_minimum_required(VERSION 3.5)

project(Framework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Framework main.cpp
    figure.cpp figure.h
    field.cpp field.h
    board.cpp board.h
    pawn.cpp pawn.h
    tower.cpp tower.h
    horse.cpp horse.h
    bishop.cpp bishop.h
    queen.cpp queen.h
    king.cpp king.h
)
