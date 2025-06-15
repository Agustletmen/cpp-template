## 概述
* cmake 编译
* ctest 测试
* cpack 创建安装包（如 .exe、.msi、.deb、.rpm、.tar.gz 等）

- CMakeLists.txt
- CMakePreset.json
- CMakeUserPresets.json


## 生成项目代码
生成ninja、msbuild、makefile等配置

```shell
cmake
-S <path-to-source>
-B <path-to-build>

# 生成器
-G <generator-name> # Unix Makefiles、Ninja、Xcode、Visual Studio 17 2022....
-A <platform-name> # 为生成器指定Architecture，仅仅对部分生成器有效 win32、x64、ARM、ARM64
-T <toolset-name> # 为生成器指定工具集，仅仅对部分生成器有效


# 缓存变量
-C <initial-cache> # 从预先写好的CMake文件中读取配置，比如文件中有 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
-D <var>[:<type>]=<value> # 创建或更新变量到CMake Cache中
-U <globbing_expr> # 从CMake Cache移除匹配的变量
-L[A][H]  # 显示 CMake 缓存中的变量
-LR[A][H] <regex> # 正则匹配缓存变量


# 预设
--preset <preset>,--preset=<preset> = Specify a configure preset.
--list-presets[=<type>]= List available presets.
--workflow [<options>] = Run a workflow preset.



-E # 执行 CMake 内置命令，无需项目构建

--toolchain <file>           = Specify toolchain file [CMAKE_TOOLCHAIN_FILE]. 指定交叉编译工具链

```





## 编译项目代码
使用上面生成的ninja、msbuild、makefile等配置来编译项目

```shell
cmake --build <directory>
--target <target>  # 通过 add_executable, add_library, 或 add_custom_target 添加的，默认情况下会构建所有目标
--config <config>
--parallel [n]  # n 表示并行任务的数量（默认为检测到的处理器核心数）
--clean-first # 先清理再构建

cmake --build --list-presets[=<type>] # List available build presets
```



**target**

- `install` 执行安装步骤，CMake 会查找所有 install() 命令并执行它们
- `clean` 清理构建目录中的生成文件
- `可执行文件、库`

**config**: 

- 这是用于多配置生成器（如 Visual Studio 或 Xcode）的选项。常见的配置包括 Debug、Release、RelWithDebInfo 和 MinSizeRel。
- 对于单配置生成器（如 Makefile 或 Ninja），这个选项通常是忽略的。



## 安装已构建的项目

把构建好的文件复制到系统中适当的位置，使其可以被其他程序或用户访问

```shell
cmake --install <directory> 
--prefix <安装路径>
--config <cfg>     = For multi-configuration tools, choose <cfg>
--component <comp> = Component-based install. Only install <comp>.
--parallel <jobs>
```
## 其他命令

```shell
cmake --fresh # configure a fresh build tree, removing any existing cache file.
cmake --open <dir> #  Open generated project in the associated application.
```

```shell
cmake -S . -B build
cmake --build build
cd build
cpack
```


cmake --fresh

cmake --help

关于msvc下导出动态链接库时，需要遵守导出约定，在实际的代码的方法头前加上 `__declspec(dllexport)`
msvc导出动态库时，不仅会导出xxx.dll，还会导出xxx.lib
在使用这个动态库时，链接时直接连接.lib文件即可，但是要把.dll放在可执行文件的同一文件目录下

`__declspec(dllimport)`



find_package()

优先级

- xxxconfig.cmake 新
- findxxx.cmake 旧

