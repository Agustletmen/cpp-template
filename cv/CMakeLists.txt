file(GLOB SRC_CODE *.c *.cpp *.cxx *.h *.hpp)
#add_library(cv SHARED ${SRC_CODE})
add_executable(cv ${SRC_CODE})

find_package(ffmpeg)
find_package(opencv)

target_link_libraries(cv PRIVATE
        ffmpeg::ffmpeg
        opencv::opencv
)