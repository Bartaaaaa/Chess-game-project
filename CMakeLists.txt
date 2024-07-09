cmake_minimum_required(VERSION 3.25)
project(projetEchiquier)

set(CMAKE_CXX_STANDARD 17)

add_executable(projetEchiquier main.cpp pions.h plateau.cpp plateau.h controleur.cpp controleur.h roi.cpp roi.h pionbasique.cpp pionbasique.h)
