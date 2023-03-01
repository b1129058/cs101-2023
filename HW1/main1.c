#include <stdio.h>

int main()
{
    int i = 0, num = 0, ct = 1;
    char a[] = "AABBBCCCCddd";
    char c = ' ';
    
    int len = sizeof(a)/sizeof(a[0])-1;
    
    for(i = 0;i<len;i++){
        if(c != a[i]){
            c = a[i];
            printf("%c", a[i]);
        }
        if(a[i] != a[i+1]){
            printf("%d", ct);
            ct = 0;
        }
        ct++;
    }

    return 0;
}
