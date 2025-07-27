```shell
# 安装conan
pip install conan
pip install conan --upgrade



# 自动根据机器来创建conan配置
conan profile detect
conan profile list
conan profile show
conan profile path

# 配置文件如下示例
# [settings]
# arch=x86_64
# build_type=Release
# compiler=gcc
# compiler.cppstd=gnu17
# compiler.libcxx=libstdc++11
# compiler.version=15
# os=Windows



https://conan.io/center
# conanfile.txt
# conanfile.py
conan install .  # conanfile.py or conanfile.txt
--output-folder=build
-b,--build=missing # 自动构建本地缺失的包, --build=boost ,build boost package
-g,--generator=
# CMakeToolchain
# CMakeDeps
# CMakeConfigDeps
# MesonToolchain
# MSBuildDeps
# MSBuildToolchain
# NMakeToolchain
# NMakeDeps
# VCVars
# VirtualRunEnv
# VirtualBuildEnv
# AutotoolsDeps
# AutotoolsToolchain
# GnuToolchain
# PkgConfigDeps
# BazelDeps
# BazelToolchain
# IntelCC
# XcodeDeps
# XcodeToolchain
# PremakeDeps
# MakeDeps
# SConsDeps
# QbsDeps
# QbsProfile
# CPSDeps
# ROSEnv
-r,--remote=conancenter
-nr,--no-remote

conan remove # 从本地缓存中删除指定的 Conan 包。
conan info # 显示有关指定 Conan 包的信息。

conan search # 搜索可用的 Conan 包。
conan search grpc* -r=conancenter

# conan仓库管理
conan remote add conancenter https://center.conan.io
#conan remote list                    # 列出所有远程仓库
#conan remote add <name> <url>        # 添加远程仓库
#conan remote update <name> <url>     # 更新远程仓库URL
```


```shell
conan install .
cmake -S . -B build/debug -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=./build/generators/conan_toolchain.cmake
cmake --build build/debug --config Release

mkdir "cmake\build"
pushd "cmake\build" # 进目录
cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_CXX_STANDARD=17 -DCMAKE_INSTALL_PREFIX=./protoc-grpc ..\..
cmake --build . --config Release --target install -j 4
popd # 返回原目录
```