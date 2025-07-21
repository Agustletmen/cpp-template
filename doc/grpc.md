```shell
protoc -I=proto/ --grpc_out=grpc --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` proto/*.proto
protoc -I=proto/ --cpp_out=grpc proto/*.proto
```


```
[settings]
arch=x86_64
build_type=Release
compiler=gcc
compiler.cppstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=13
os=Linux


[conf]
tools.cmake.cmaketoolchain:generator=Ninja

```


env:gcc/g++、cmake、ninja、conan2
pkg:
grpc
fmt
boost
zlib
bzip2
openssl
opencv
qt


```shell
apt udpate
apt install cmake
apt install ninja-build
apt install build-essential

```