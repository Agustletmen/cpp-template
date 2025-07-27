cmake_minimum_required(VERSION 3.15)
project("CMakeProject") # 会自动设置变量`CMAKE_PROJECT_NAME`为该值
cmake_policy(SET CMP0167 OLD)




add_subdirectory(util) # 添加子目录（需该目录下有自己的CMakeLists.txt）
#add_custom_target() # 自定义构建目标
#add_custom_command() # 自定义构建命令
# https://cmake.org/cmake/help/git-master/command/add_library.html#command:add_library

# add_executable(${CMAKE_PROJECT_NAME} ${SRC_CODE})
# add_library(${CMAKE_PROJECT_NAME} SHARED ${SRC_CODE}) 动态链接库，可以被多个应用程序使用。
# add_library(${CMAKE_PROJECT_NAME} STATIC ${SRC_CODE}) 静态链接库
# add_library(${CMAKE_PROJECT_NAME} MODULE ${SRC_CODE}) 特定用途的动态链接库，用于实现特定功能，通常在运行时被加载。

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# 强制使用上面的标准
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# 开启编译器的拓展功能
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_EXTENSIONS ON)
#set(CMAKE_C_COMPILER)
#set(CMAKE_CXX_COMPILER)

message(CMAKE_BINARY_DIR ==> ${CMAKE_BINARY_DIR})
set(CMAKE_TOOLCHAIN_FILE build/generators/conan_toolchain.cmake)
set(CMAKE_PREFIX_PATH build/generators/)


set(CMAKE_BUILD_TYPE Release)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif ()
message("Build type: " ${CMAKE_BUILD_TYPE})

# include(cmake/env.cmake)
# print_all_variables()# 使用宏


# find_package() # 模块模式、配置模式
# find_path() # 查找包含特定文件的目录并设置变量
# find_file() # 查找任意类型的文件并设置变量
# find_program() # 查找可执行文件并设置变量
# find_library() # 查找库文件并设置变量以供后续链接使用
find_package(Boost)
find_package(gRPC)
find_package(fmt)


message(QT_PLUGIN_PATH ==> ${QT_PLUGIN_PATH})

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
# aux_source_directory(. DIR_SRCS)
# add_executable(${CMAKE_PROJECT_NAME} ${DIR_SRCS})
add_executable(${CMAKE_PROJECT_NAME} main.cpp)


# 文件操作：READ、WRITE、APPEND、COPY、REMOVE、RENAME、MAKE_DIRECTORY、GLOB、MD5、DOWNLOAD……
# file(GLOB SRC_CODE *.c *.cpp *.cxx *.h *.hpp)
# file(GLOB SRC_CODE
#  "${PROJECT_SOURCE_DIR}/include/*.h"
#  "${PROJECT_SOURCE_DIR}/include/*.hpp"
#  "${PROJECT_SOURCE_DIR}/src/*.cpp"
#  "${PROJECT_SOURCE_DIR}/src/*.cxx"
#  "${PROJECT_SOURCE_DIR}/src/*.c"
#  "${PROJECT_SOURCE_DIR}/src/*.cc"
# )

#执行外部命令
#execute_process()

# 为指定目标设置包含目录，以供编译时查找头文件
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        util/math
)

# 为目标添加额外源文件
#target_sources(${CMAKE_PROJECT_NAME} PRIVATE
# ${LIB_SOURCE}
#)






# 指定链接器查找库文件的路径
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE

)

# 为目标链接依赖的库
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        boost::boost
        grpc::grpc
        fmt::fmt
)


# target_link_options() # 为指定目标设置链接器选项

#target_compile_options() # 指定目标设置编译器选项
#target_compile_features()

# 为目标定义编译宏（源代码中可直接使用）
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        HELLO=WORLD
)

#target_precompile_headers()


#cmake --install
#set(CMAKE_INSTALL_PREFIX "/usr/local/bin")
#install(TARGETS ${CMAKE_PROJECT_NAME}
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#)
#install(DIRECTORY include/
#        DESTINATION include)

#ctest
#enable_testing()
#add_test(NAME my_test COMMAND my_test_executable)