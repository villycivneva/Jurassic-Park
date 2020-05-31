cmake_minimum_required(VERSION 3.15)
project(JurassicPark)

set(CMAKE_CXX_STANDARD 14)

add_executable(JurassicPark main.cpp Dinosaur.cpp Dinosaur.h Carnivorous.cpp Carnivorous.h Herbivorous.cpp Herbivorous.h Aqueous.cpp Aqueous.h Flying.cpp Flying.h Cage.cpp Cage.h)