cmake_minimum_required(VERSION 3.22)
project(json_store C)

set(CMAKE_C_STANDARD 17)

add_library(json_store libjson_store.c)
