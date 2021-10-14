#! /usr/bin/env bash

# 要想使用外部变量, 包含外部变量的源文件(不能有main)必须和含有main的源文件一起编译

gcc ./外部变量_main主执行.c ./外部变量_数据部分.c -o 外部变量.out
./外部变量.out