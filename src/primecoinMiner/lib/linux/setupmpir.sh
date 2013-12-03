#!/bin/sh
git clone --depth 1 https://github.com/wbhart/mpir.git
cd mpir
./configure
make
make check
