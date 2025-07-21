cmake_minimum_required(VERSION 3.15)
# set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES conan_provider.cmake)
project("CMakeProject")

#添加子目录（包含其 CMakeLists.txt）
add_subdirectory(mathlib)
#add_custom_target() # 自定义构建目标
#add_custom_command() # 自定义构建命令
# https://cmake.org/cmake/help/git-master/command/add_library.html#command:add_library

# add_executable(${CMAKE_PROJECT_NAME} ${SRC_CODE})
# add_library(${CMAKE_PROJECT_NAME} SHARED ${SRC_CODE}) 通用动态链接库，可以被多个应用程序使用。
# add_library(${CMAKE_PROJECT_NAME} STATIC ${SRC_CODE})
# add_library(${CMAKE_PROJECT_NAME} MODULE ${SRC_CODE}) 特定用途的动态链接库，用于实现特定功能，通常在运行时被加载。

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_COMPILER)
#set(CMAKE_CXX_COMPILER)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/build/generators/)
#set(CMAKE_TOOLCHAIN_FILE ${CMAKE_BINARY_DIR}/build/generators/conan_toolchain.cmake)
#set(CMAKE_BUILD_TYPE Release)


include(cmake/env.cmake)
print_all_variables()# 使用宏



# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
# aux_source_directory(. DIR_SRCS)
# add_executable(${CMAKE_PROJECT_NAME} ${DIR_SRCS})

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# include(${CMAKE_BINARY_DIR}/build/generators/BoostConfig.cmake)
#find_package(Boost REQUIRED)
#message("${Boost_INCLUDE_DIRS}")
#target_link_libraries(${CMAKE_PROJECT_NAME} boost::boost)

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


# find_package() # 模块模式、配置模式
# find_path() # 查找包含特定文件的目录并设置变量
# find_file() # 查找任意类型的文件并设置变量
# find_program() # 查找可执行文件并设置变量
# find_library() # 查找库文件并设置变量以供后续链接使用


# target_include_directories() # 为指定目标设置包含目录，以供编译时查找头文件

# target_link_libraries() # 为指定目标添加链接库或依赖
# target_link_directories() # 过去用于设置链接目录，但现在通常不需要直接使用
# target_link_options() # 为指定目标设置链接器选项

#target_compile_options() # 指定目标设置编译器选项
#target_compile_features()
#target_compile_definitions()

#target_precompile_headers()
#target_sources()


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