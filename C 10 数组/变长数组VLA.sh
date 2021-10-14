#! /usr/bin/env bash

echo "得使用C++编译器才能编译有变长数组源代码, C11标准虽然说可以这样, 但是没有强制编译器这样."

g++ 变长数组VLA.c -o 变长数组VLA.out