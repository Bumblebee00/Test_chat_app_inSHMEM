#!/bin/bash

# This file should be able to install all dependencies.
# The execution of this script should work without problems in case of already configured dependencies.
# Please keep this in mind while coding.

# Inits git submodules
if [[ $(git submodule status | grep tests/googletest) ]]; then
  # google submodule installed
  echo "Google Test submodule installed correctly"
else
  # google submodule not installed
  git submodule add https://github.com/google/googletest.git tests/googletest
fi
git submodule update --init --recursive

# Install mosquitto
sudo apt install -y libmosquitto-dev

# Install toml11 library
if [[ $(ls /usr/local/include | grep toml) ]]; then
  # Toml installed
  echo "toml11 library already installed"
else
  # Toml not installed
  git clone https://github.com/ToruNiina/toml11.git
  cd toml11
  mkdir build
  cd build
  cmake -Dtoml11_BUILD_TEST=OFF cmake -DCMAKE_CXX_STANDARD=C++17 ..
  make
  sudo make install
  cd ../..
  sudo rm -f -r toml11
fi

# Install google test library
if [[ $(ls /usr/local/include | grep gtest) ]]; then
  # Google Test installed
  echo "gtest library already installed"
else
  # Google Test not installed
  git clone https://github.com/google/googletest.git
  cd googletest
  mkdir build
  cd build
  cmake ..
  make
  sudo make install
  cd ../..
  sudo rm -f -r googletest
fi
