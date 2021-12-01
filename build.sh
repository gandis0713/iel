#!/usr/bin/zsh

rm -rf build
mkdir build
cd build
cmake -DTEST_SPEC=ON ..
make

# run test spec
./spec/test_spec