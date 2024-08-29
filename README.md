
* cmake
* ctest
* cpack



## 生成项目代码


```shell
cmake
-S <path-to-source>
-B <path-to-build>
-G <Generator>
-A <Architecture>
-D 设置变量
-E 执行命令
```





## 编译项目代码


```shell
cmake --build <directory>
--target <target>  # 通过 add_executable, add_library, 或 add_custom_target 添加的，默认情况下会构建所有目标
--config <config>
--parallel [n]  # n 表示并行任务的数量（默认为检测到的处理器核心数）
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

