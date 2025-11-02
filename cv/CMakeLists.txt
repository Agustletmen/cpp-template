file(GLOB SRC_CODE *.c *.cpp *.cxx *.h *.hpp)
add_library(cv SHARED ${SRC_CODE})