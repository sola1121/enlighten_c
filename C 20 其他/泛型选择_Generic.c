# include "stdio.h"

# define PRLN(s) printf(#s "变量类型为: %s.\n", s)

# define TYPE(value) _Generic((value), \
    int: "int", \
    float: "float", \
    double: "double", \
    char *: "char *", \
    default: "其他" \
)


int main(){
    int v1;
    float v2;
    double v3;
    char * v4;
    long v5;

    PRLN(TYPE(v3));
    PRLN(TYPE(v1));
    PRLN(TYPE(v2));
    PRLN(TYPE(v4));
    PRLN(TYPE(v5));

    return 0;
}
