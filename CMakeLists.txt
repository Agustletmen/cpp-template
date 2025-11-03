#命令、关键字不区分大小写；变量区分大小写


cmake_minimum_required(VERSION 3.15) # 指定 CMake 最低版本（必须放在最前面）
cmake_policy(SET CMP0167 OLD) # 将策略 CMP0167 设置为使用旧版本的行为。
#cmake_policy(SET CMP0091 NEW)
project("CMakeProject" # CMAKE_PROJECT_NAME
        VERSION 1.0.0
        DESCRIPTION "A cross-platform app"
        HOMEPAGE_URL agustletmen.github.io
        LANGUAGES C CXX
)




#定义变量：set(变量名 变量值1 变量值2 ...)（变量值可多个，用空格分隔）；
#引用变量：${变量名}（在字符串中也可直接引用，如 "${PROJECT_NAME}_app"）；
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# 强制要求指定标准，不满足则报错
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 禁用编译器扩展（保证跨平台兼容性）
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)

#指定编译器
#set(CMAKE_C_COMPILER)
#set(CMAKE_CXX_COMPILER)


set(CMAKE_TOOLCHAIN_FILE build/generators/conan_toolchain.cmake)
set(CMAKE_PREFIX_PATH build/generators/)


set(CMAKE_BUILD_TYPE Release)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif ()
message("Build type: " ${CMAKE_BUILD_TYPE})

include(cmake/env.cmake)
print_all_variables()# 使用宏
# custom_print_variables()# 使用宏


# find_package() # 模块模式、配置模式
# find_path() # 查找包含特定文件的目录并设置变量
# find_file() # 查找任意类型的文件并设置变量
# find_program() # 查找可执行文件并设置变量
# find_library() # 查找库文件并设置变量以供后续链接使用
#find_package(库名 [版本] [REQUIRED] [COMPONENTS 组件])
find_package(Boost)
#find_package(gRPC)
find_package(fmt)
find_package(ffmpeg)
find_package(opencv)


#==============================================文件操作====================================================
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


# aux_source_directory(. DIR_SRCS)  # 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
# add_executable(${CMAKE_PROJECT_NAME} ${DIR_SRCS})

#执行外部命令
#execute_process()

#==============================================编译====================================================
# https://cmake.org/cmake/help/git-master/command/add_library.html#command:add_library
# add_executable(${CMAKE_PROJECT_NAME} ${SRC_CODE})
# add_library(${CMAKE_PROJECT_NAME} SHARED ${SRC_CODE}) 动态链接库，可以被多个应用程序使用。
# add_library(${CMAKE_PROJECT_NAME} STATIC ${SRC_CODE}) 静态链接库
# add_library(${CMAKE_PROJECT_NAME} MODULE ${SRC_CODE}) 特定用途的动态链接库，用于实现特定功能，通常在运行时被加载。

#「先定义目标（add_），再精准配置依赖（target_）」

#优先用 “目标级命令”，少用 “全局命令”
#include_directories()
#link_directories()
#link_libraries()

# 添加子目录（需该目录下有自己的CMakeLists.txt）
add_subdirectory(util)
add_subdirectory(cv)
add_subdirectory(syntax)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# target_compile_options() # 指定目标设置编译器选项
# target_compile_features() # 为指定目标设置编译特性
# target_compile_definitions()

# 为指定目标设置包含目录，以供编译时查找头文件
# target_include_directories(目标名 作用域 路径1 路径2 ...)
target_include_directories(${CMAKE_PROJECT_NAME}
        PRIVATE # 仅当前目标生效（内部头文件，不对外暴露）
        util/math
        #        PUBLIC   # 当前目标+依赖它的目标生效（对外暴露的头文件）
        #        INTERFACE # 仅对外暴露，自身不用
)


#==============================================链接====================================================
# target_link_options() # 为指定目标设置链接器选项


# 指定链接器查找库文件的搜索路径
target_link_directories(${CMAKE_PROJECT_NAME}
        PRIVATE
)

# 为目标链接所需的库文件
# target_link_libraries(目标名 作用域 库名1 库名2 ...)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
        boost::boost
#        grpc::grpc
        fmt::fmt
        ffmpeg::ffmpeg
)

#==============================================测试====================================================
#ctest
#enable_testing()
#add_test(NAME my_test COMMAND my_test_executable)

#==============================================安装====================================================
#cmake --install
#set(CMAKE_INSTALL_PREFIX "/usr/local/bin")

# 安装可执行文件
#install(TARGETS ${CMAKE_PROJECT_NAME}
#        RUNTIME DESTINATION bin  # 可执行文件
#        LIBRARY DESTINATION lib  # 动态库
#        ARCHIVE DESTINATION lib  # 静态库
#)

# 安装头文件
#install(DIRECTORY include/
#        DESTINATION include
#        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"  # 仅安装头文件
#)