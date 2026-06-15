#!/bin/bash

if [ ! -d "build" ]; then
    meson setup build
fi

meson compile -C build
cd build

case "$OSTYPE" in
  linux*)
    ./internet-banking
    ;;
  darwin*)
    ./internet-banking
    ;;
  msys* | cygwin* | mingw*)
    ./internet-banking.exe
    ;;
esac
