#!/usr/bin/env bash

if [[ "$TRAVIS_OS_NAME" == "osx" ]]
then
export PATH=$PATH:/usr/local/opt/ccache/libexec

fi
if [[ "$TRAVIS_OS_NAME" == "linux" ]]
then
export LD_LIBRARY_PATH=$HOME/deps/lib:$LD_LIBRARY_PATH
fi
mkdir -p $HOME/built
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX:PATH=$HOME/built ..
make
make install

