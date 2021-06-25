cmake_minimum_required(VERSION 3.0.0)
project(Human VERSION 0.1.0)

find_package(pybind11 CONFIG REQUIRED)  

pybind11_add_module(Human main.cpp People.cpp)
