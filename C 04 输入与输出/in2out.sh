#! /bin/bash

# 利用系统重定向功能, 将input_text.txt中的内容作为输入到echo.out, 并输出到output_text.txt中
# < 重定向输入, > 重定向输出

./echo.out < ./input_text.txt > output_text.txt
