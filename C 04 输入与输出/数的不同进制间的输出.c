# include "stdio.h"
# include "limits.h"

# define integer_format1 "格式1 oct: %o, dec: %d, hex: %x, unsigned: %u\n"
# define integer_format2 "格式2 oct: %#o, dec: %d, hex: %#x, unsigned: %u\n"


int main(){
    
    // short 至少16位, 共两个字节, 有符号表示范围-2¹⁵ ~ 2¹⁵-1, 无符号表示范围 0 ~ 2¹⁶-1
    // 即表示 -32768 ~ 32767, 0 ~ 65535

    printf("当前系统short范围: %d ~ %d\n", SHRT_MIN, SHRT_MAX);

    short num = 253,   // 正数以原码的形式在系统中直接存储
          neg_num = -3;   // 负数以补码的形式在系统中存储

    /*
        -3的二进制
        首先3的short二进制为 00000000 00000011
        在系统中先取反码在加一形成补码, 为 11111111 11111100 + 1
        所以在系统中 -3的存储为 1111111 11111101

        当 11111111 11111101作为八进制或十六进制输出的时候, 就是直接将其转换为对应的

        那么 1 111 111 111 111 101 对应八进制为 177775
        1111 1111 1111 1101 对应的十六进制为 fffd
    */
         
    printf(integer_format1, num, num, num, (unsigned)num);
    printf(integer_format1, neg_num, neg_num, neg_num, (unsigned)neg_num);

    putc('\n', stdout);

    printf(integer_format2, num, num, num, (unsigned)num);
    printf(integer_format2, neg_num, neg_num, neg_num, (unsigned)neg_num);

    return 0;
}