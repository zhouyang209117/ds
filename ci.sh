#!/bin/bash
set -e

cmake .
make
cd ./app/list
./noise.out
cd ../..
./app/list/list_sq.out
./app/list/list_sq1.out
./app/list/list_link.out
./app/list/list_clink.out
./app/list/simple_sq.out
./app/list/simple_link.out
./app/list/simple_clink.out
./app/tree/tree_bi.out
./tests/unittest_list.out
./tests/unittest_link_list.out
./tests/unittest_clink_list.out
./tests/unittest_dclink_list.out
./tests/unittest_stack.out
./tests/unittest_sq_stack.out
./tests/unittest_sq_queue.out
./tests/unittest_tree_bi.out
