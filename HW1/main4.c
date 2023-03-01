#include <stdio.h>

int main()
{
    char a[] = "ac-99bc";
    int i = 0, j = 0;
    int start_index = 0, end_index = 0, num  = 0;
    
    int len = sizeof(a)/sizeof(a[0])-1;
    
    for (int i=0; i<len;i++) {
        if (a[i]>='0' && a[i]<='9') {
            start_index = i;
            end_index = i;
            j  = i+1;
            while((a[j]>='0' && a[j]<='9')){
                end_index = j;
                j++;
            }
            break;
        }
        
    }
    
    for(i = start_index;i<=end_index;i++){
        num = (num*10) + (a[i]-'0');
    }
    if(start_index!=0 && a[start_index-1] == '-')
        num *= -1;
    
    printf("%d", num);
    
    
}
