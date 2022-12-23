# include "stdio.h"


/*
    给定一个字符串, 依次提取其中的单词
*/


// 是否为字母
_Bool is_alpha(char ch){
    if (('A'<=ch && 'Z'<=ch) || ('a'<=ch && 'z'<=ch))
        return 1;
    return 0;
}


// 是否为空格
_Bool is_space(char ch){
    return ch == ' ';
}


// 是否为结束符
_Bool is_eof(char ch){
    return ch == '\0';
}


// 输出指定位置的子串
void output(char * str, size_t len){
    char * pt = str;
    for (int i=0; i<len; i++)
        putchar(*(pt+i));
    putchar('\n');
}


/* 
    挨个遍历, 提取字符
    左指针指向单词开头, 即字符
    右指针遍历字符串, 每当是字符, count增1, 用于知道该单词的长度, 以便输出
    当右指针遍历到空格, 然后再到单词, 将左指针指向单词开头
*/
void output_word(char *str){
    size_t count = 0;   // 当前单词的长度
    int sign = 0;   // 当前字符前驱是否是空格, 如果是, 将left定位到新的单词开头
    char * left, * right;
    left = right = str;

    while (!is_eof(*right)) {
        if (is_alpha(*right)){   // 字符开始计数
            if (sign==1){
                left = right;   // 上一个字符为空格, 重新将left定位到新单词开头
                sign = 0;
            }
            count += 1;
        }

        right += 1;

        if (is_space(*right) || is_eof(*right)) {
            output(left, count);   // 输出上一个单词
            count = 0;   // 清空长度
            sign = 1;   // 当前字符前不是空格, 即当前为空字符
        }
    }    

}


int main(){
    char * str = "the sky is blue";

    output_word(str);

    return 0;
}