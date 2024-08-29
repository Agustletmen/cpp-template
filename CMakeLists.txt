cmake_minimum_required(VERSION 3.8)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif()

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif ()



project("CMakeProject")
add_subdirectory(mathlib)
add_subdirectory(cv)
add_subdirectory(media)


# include(CPack)
include(cmake/env.cmake)
print_all_variables()# 使用宏

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

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



# 输出结果：可执行文件|动态链接库|静态链接库
# add_executable(${CMAKE_PROJECT_NAME} ${SRC_CODE})

# https://cmake.org/cmake/help/git-master/command/add_library.html#command:add_library
#add_library(${CMAKE_PROJECT_NAME} SHARED ${SRC_CODE}) 通用动态链接库，可以被多个应用程序使用。
#add_library(${CMAKE_PROJECT_NAME} STATIC ${SRC_CODE})
#add_library(${CMAKE_PROJECT_NAME} MODULE ${SRC_CODE}) 特定用途的动态链接库，用于实现特定功能，通常在运行时被加载。


# find_package(fmt REQUIRED)
# if(fmt_FOUND)
#     include_directories(${fmt_INCLUDE_DIRS})
#     target_link_libraries(${CMAKE_PROJECT_NAME} ${fmt_LIBRARIES})
# else()
#     message(FATAL_ERROR "fmt library not found")
# endif()

# include_directories(<items>) # 不推荐，添加包含目录到指定目标或全局
# target_include_directories() # 为指定目标设置包含目录，以供编译时查找头文件





# link_libraries(<items>) # 不推荐
# target_link_libraries() # 为指定目标添加链接库或依赖
# target_link_directories() # 过去用于设置链接目录，但现在通常不需要直接使用
# target_link_options() # 为指定目标设置链接器选项

# target_compile_options() # 指定目标设置编译器选项
# target_compile_definitions() # 为指定目标设置编译时宏定义
# target_compile_features() # 请求启用特定的编译器特性



# if (CMAKE_VERSION VERSION_GREATER 3.12)
#     set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
# endif ()


# find_package() # 加载对应名字的Find<PackageName>.cmake
# find_path() # 查找给定的头文件目录路径
# find_program() # 查找可执行文件并设置变量
# find_library() # 查找库文件并设置变量以供后续链接使用
# find_file() # 查找任意类型的文件并设置变量


# 执行 cmake --install 时会进行以下操作
# set(CMAKE_INSTALL_PREFIX "/opt/my_project")
# install(TARGETS ${CMAKE_PROJECT_NAME}
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib
#        )
# install(DIRECTORY include/
#         DESTINATION include)

# add_test()