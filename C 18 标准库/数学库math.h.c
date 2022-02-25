# include "stdio.h"
# include "math.h"

# define RAD_TO_DEG (180/(4*atan(1)))   // 弧度转换为角度


// 极坐标
typedef struct polar_v {
    double magnitude;
    double angle;
} Polar_V;


// 横纵坐标
typedef struct rect_v {
    double x;
    double y;
} Rect_V;


// 横纵坐标转换为极坐标
Polar_V rect_to_polar(Rect_V rv) {
    Polar_V pv;

    pv.magnitude = sqrt(rv.x*rv.x + rv.y*rv.y);
    if (pv.magnitude == 0)
        pv.angle = 0.0;
    else
        pv.angle = RAD_TO_DEG * atan2(rv.y, rv.x);
    
    return pv;
}


int main(){

    printf("圆周率为: %lf\n", M_PI);
    printf("sin(π/2) = %.2lf  ", sin(M_PI/2));
    printf("sin(π/3) = %.2lf  ", sin(M_PI/3));
    printf("sin(π/4) = %.2lf  ", sin(M_PI/4));
    printf("sin(π/6) = %.2lf\n", sin(M_PI/6));
    printf("cos(π/2) = %.2lf  ", cos(M_PI/2));
    printf("cos(π/3) = %.2lf  ", cos(M_PI/3));
    printf("cos(π/4) = %.2lf  ", cos(M_PI/4));
    printf("cos(π/6) = %.2lf\n", cos(M_PI/6));
    printf("tan(π/2) = %.2lf  ", cos(M_PI/2));
    printf("tan(π/3) = %.2lf  ", cos(M_PI/3));
    printf("tan(π/4) = %.2lf  ", cos(M_PI/4));
    printf("tan(π/6) = %.2lf\n", cos(M_PI/6));

    Rect_V input;
    Polar_V result;

    input.x = 5.0;
    input.y = 12.0;

    result = rect_to_polar(input);

    printf("x = %.2lf, y = %.2lf\n", input.x, input.y);
    printf("magnitude = %.2lf, angle = %.2lf\n", result.magnitude, result.angle);

    return 0;
}