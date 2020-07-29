#!/bin/bash
set -e

cmake .
make
./tests/unittest_stack.out
./tests/unittest_list.out