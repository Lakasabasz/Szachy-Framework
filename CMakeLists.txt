cmake_minimum_required(VERSION 3.5)

project(Framework LANGUAGES CXX VERSION 1.1.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Framework
    figure.cpp figure.h
    field.cpp field.h
    board.cpp board.h
    pawn.cpp pawn.h
    tower.cpp tower.h
    horse.cpp horse.h
    bishop.cpp bishop.h
    queen.cpp queen.h
    king.cpp king.h
    history.cpp history.h
    exceptions/coordsoutofboardexception.cpp exceptions/coordsoutofboardexception.h
    exceptions/usagewrongmovementexception.cpp exceptions/usagewrongmovementexception.h
    enums.h
)

add_executable(Test-main test_main.cpp)
add_executable(Test-unit test_unit.cpp)

target_link_libraries(Test-main PRIVATE Framework)
