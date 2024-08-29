cmake_minimum_required(VERSION 3.8)

project("mathlib")

file(GLOB SRC_CODE
 "./include/*.h"
 "./include/*.hpp"
 "./src/*.cpp"
 "./src/*.cxx"
 "./src/*.c"
 "./src/*.cc"
 )

add_library(mathlib STATIC ${SRC_CODE})