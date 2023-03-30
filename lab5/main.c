#include <stdio.h>

typedef int (*calc_func)(int, int);

int add(int x, int y){
    return x+y;
}

int sub(int x, int y){
    return x-y;
}

int mul(int x, int y){
    return x*y;
}

int div_(int x, int y){
    return x/y;
}

int calc(calc_func calc_ptr, int a, int b){
    return calc_ptr(a, b);
}

int main(){
    printf("sum = %d\n", calc(add, 4, 2));
    printf("dif = %d\n", calc(sub, 4, 2));
    printf("product = %d\n", calc(mul, 4, 2));
    printf("quotient = %d\n", calc(div_, 4, 2));
    return 0;
}
