#!/bin/bash

set -e

conan profile detect --force
conan install . --build=missing -pr=./profiles/linux-gcc20-release
cmake --list-presets
cmake --preset=conan-release
cmake --build --preset=conan-release
./build/Release/smtpBot
