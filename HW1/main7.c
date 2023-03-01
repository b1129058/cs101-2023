#include <stdio.h>

int main()
{
    char b[] = "10001111";
    char a[] = "10011110";
    int cnt = 3, sum = 0, coef = 8, i = 0;
    int o[16] = {'0', '1' , '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    
    int len = sizeof(a)/sizeof(a[0])-1;
    for (i=0; i<len;i++) {
        
        if (a[i]-'0' == 1)
            sum += (a[i]-'0')*coef;
        
        coef /=2;
        
        if(coef == 0){
            printf("%c", o[sum]);
            sum = 0;
            coef = 8;
        }
    }
    
    return 0;
    
}
