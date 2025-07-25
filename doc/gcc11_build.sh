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






