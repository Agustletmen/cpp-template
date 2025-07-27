macro(print_all_variables)
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=>${${_variableName}}")
    endforeach()
endmacro()

# CMake 内置变量
# 指定编译工具链：-DCMAKE_TOOLCHAIN_FILE=toolchain.cmake
# 设置构建类型：-DCMAKE_BUILD_TYPE=Release
# 指定安装路径：-DCMAKE_INSTALL_PREFIX=/usr/local

#CMAKE_PREFIX_PATH
#CMAKE_MODULE_PATH
#CMAKE_INCLUDE_PATH
#CMAKE_LIBRARY_PATH
#CMAKE_MAKE_PROGRAM 是 CMake 中用于指定构建工具（make 程序）路径的变量