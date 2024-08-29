cmake_minimum_required(VERSION 3.8)

project("cv")

file(GLOB SRC_CODE
 "./include/*.h"
 "./include/*.hpp"
 "./src/*.cpp"
 "./src/*.cxx"
 "./src/*.c"
 "./src/*.cc"
)

add_executable(${PROJECT_NAME} ${SRC_CODE})


include_directories(/root/lib/opencv4.10.0_install/include/opencv4)

file(GLOB OpenCV_LIB 
    "/root/lib/opencv4.10.0_install/lib/*.so"
)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIB})

set(INSTALL_DIR "/opt/install")

# 安装可执行文件
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${INSTALL_DIR}/bin
    LIBRARY DESTINATION ${INSTALL_DIR}/lib
    ARCHIVE DESTINATION ${INSTALL_DIR}/lib
)

# 复制 OpenCV 库文件到可执行文件所在目录
install(FILES ${OpenCV_LIB}
    DESTINATION ${INSTALL_DIR}/lib
)