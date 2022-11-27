# include "stdio.h"
# include "limits.h"

char * int_to_binary(int, char *);
void show_binary_string(const char *);
int invert_end(int, int);


int main(){
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int num;
    
    puts("输入要转化为二进制形式的整数:\n");
    while (scanf("%d", &num)==1){
        int_to_binary(num, bin_str);
        printf("对应二进制为: ");
        show_binary_string(bin_str);

        putchar('\n');

        num = invert_end(num, 4);
        printf("反转后四位为: ");
        int_to_binary(num, bin_str);
        show_binary_string(bin_str);

        putchar('\n');
    }

    return 0;
}


// 使用右移操作与位与运算, 将整数转换为二进制字符
char * int_to_binary(int num, char *pt){
    int i;
    const int size = CHAR_BIT * sizeof(int);

    for (i=size-1; i>=0; i--, num>>=1)
        pt[i] = (01 & num) + '0';
    
    pt[size] = '\0';

    return pt;
}


// 使用取模运算, 将整数转换为二进制字符
char * int_to_binary2(int num, char *pt){
    int i;
    const int size = CHAR_BIT * sizeof(int);

    for (i=size-1; i>=0; i--, num/=2)
        pt[i] = num%2 + '0';

    return pt;
}


// 以4位为一组, 显示二进制字符串
void show_binary_string(const char * bin_str){
    int i=0;

    while (bin_str[i]){
        putchar(bin_str[i]);
        if (++i % 4==0 && bin_str[i])
            putchar(' ');
    }
}


// 将所给num的后bits位取反
int invert_end(int num, int bits){
    int mask = 0;
    int bit_val = 1;

    // 按要求的bits位取掩码
    while (bits-- >0){
        mask |= bit_val;   // 0000|0001=0001, 0001|0010=0011, 0011|0100=0111, 0111|1000=1111
        bit_val <<= 1;   // 10, 100, 1000, 10000(这一个不会参与运算)
    }

    return num ^ mask;
}