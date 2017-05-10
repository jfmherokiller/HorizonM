#!/usr/bin/env bash

if [[ "$TRAVIS_OS_NAME" == "osx" ]]
then
brew update
brew install sdl2 jpeg-turbo ccache
fi

if [[ "$TRAVIS_OS_NAME" == "linux" ]]
then
mkdir -p ~/deps
wget https://www.libsdl.org/release/SDL2-2.0.5.tar.gz
tar xf SDL2-2.0.5.tar.gz
cd SDL2-2.0.5
./configure --prefix=$HOME/deps
make
make install
fi
