cmake_minimum_required(VERSION 3.8)

project("media")
message(STATUS "PROJECT_NAME ==> ${PROJECT_NAME}")
file(GLOB SRC_CODE
 "./include/*.h"
 "./include/*.hpp"
 "./src/*.cpp"
 "./src/*.cxx"
 "./src/*.c"
 "./src/*.cc"
)

add_executable(${PROJECT_NAME} ${SRC_CODE})

include_directories(D:/SDK/3rd/ffmpeg-7.0.2-full_build-shared/include)
file(GLOB FFMPEG_LIBS "D:/SDK/3rd/ffmpeg-7.0.2-full_build-shared/lib/*")
target_link_libraries(${PROJECT_NAME} ${FFMPEG_LIBS})

# file(GLOB FFMPEG_DLL "D:/SDK/3rd/ffmpeg-7.0.2-full_build-shared/bin/*.dll")
# target_link_libraries(${PROJECT_NAME} ${FFMPEG_DLL})