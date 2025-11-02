file(GLOB SRC_CODE *.c *.cpp *.cxx *.h *.hpp)
#add_library(cv SHARED ${SRC_CODE})
add_executable(cv ${SRC_CODE})

find_package(ffmpeg)

target_link_libraries(cv PRIVATE
        ffmpeg::ffmpeg
)