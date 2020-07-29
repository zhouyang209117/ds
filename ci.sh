#!/bin/bash
set -e

cmake .
make
cd ./app/list
./noise.out
cd ../..
./app/list/list_sq.out
./app/list/list_link.out
./app/list/list_clink.out
./app/list/simple_sq.out
./tests/unittest_stack.out
./tests/unittest_list.out