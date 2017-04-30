#!/bin/bash

mkdir Hz
lzma -dcv Hz.tar.lzma | tar -C Hz -xvf -
