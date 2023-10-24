cmake_minimum_required(VERSION 3.20)
project(Sand_heap_with_BMP_export)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sand_heap_with_BMP_export main.cpp lib/parser/parce.cpp lib/parser/parce.h lib/model/sand.cpp lib/model/sand.h lib/viewer/image.cpp lib/viewer/image.h)
