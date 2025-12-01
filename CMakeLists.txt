cmake_minimum_required(VERSION 4.0)
project(ac_trainer_coded)

set(CMAKE_CXX_STANDARD 20)

add_executable(ac_trainer_coded main.cpp
        memory.cpp
        Memory.h
        godmode.cpp
        godmode.h
        killall.cpp
        killall.h
)
