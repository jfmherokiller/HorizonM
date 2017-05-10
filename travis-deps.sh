#!/usr/bin/env bash

if [[ "$TRAVIS_OS_NAME" == "osx" ]]
then
brew update
brew install sdl2 jpeg-turbo
fi
