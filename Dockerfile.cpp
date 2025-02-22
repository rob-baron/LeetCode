FROM ubuntu:24.04

# this sets up the development environment
# gives us some development tools + google test
RUN apt-get update \
    && apt-get install -y build-essential libtool autoconf unzip wget gcc g++ libssl-dev git gdb curl valgrind flex bison\
    && mkdir -p /App \
    && cd /App \
    && wget https://github.com/Kitware/CMake/releases/download/v3.27.9/cmake-3.27.9.tar.gz \
    && tar -zxvf cmake-3.27.9.tar.gz \
    && cd cmake-3.27.9 \
    && ./bootstrap \
    && make install \
    && cd /App \
    && git clone https://github.com/google/googletest.git -b v1.14.0 \
    && cd googletest \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make all \
    && make install

WORKDIR /App

ENTRYPOINT [ bash ]
