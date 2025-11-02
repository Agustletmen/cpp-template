C 标准
- C89
- C99	
- C11
- C17
- C23

C++ 标准
- C++98、C++03 
- C++11、C++14、C++17 
- C++20、C++23、C++26

查看所需的链接文件
```shell
ldd <executable>
```



conan install . -s build_type=Debug  --build=missing

## 使用grpc
```shell
protoc -I=proto/ --grpc_out=grpc --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` proto/*.proto
protoc -I=proto/ --cpp_out=grpc proto/*.proto
```

## conan
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


## 安装gcc11
```shell
wget https://gcc.gnu.org/pub/gcc/releases/gcc-11.5.0/gcc-11.5.0.tar.gz
mkdir "gcc11_source"
tar -zxf gcc-11.5.0.tar.gz -C gcc11_source

cd gcc11_source
./contrib/download_prerequisites

mkdir build
cd build
../configure --enable-checking=release --enable-language=c,c++ --disable-multilib --prefix=/usr
make -j4

sudo make install
gcc --version
```