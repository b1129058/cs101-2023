#include <stdio.h>

int main()
{
    char a[] = "-9 8 7 6 5 -4 3 -2 1";
    int i = 4;
    int j = 0, k =  0, tmp = 0, sign  = 1;
    int start_index = 0, end_index = 0;
    
    int len = sizeof(a)/sizeof(a[0])-1;
    int arr[len/2];
    
    for (int j=0; j<=len;j++) {
        if(a[j] == '-'){
            sign = -1;
        }
        else if (a[j]>='0' && a[j]<='9') {
            tmp = (tmp*10) + (a[j]-'0');
        }

        else{
            arr[end_index] = sign * tmp;
            end_index += 1;
            tmp = 0;
            sign = 1;
        }
        
    }
    
    
    for(k = 0;k<=end_index-2;k++){
        for(j = k+1;j<=end_index-1;j++){
            if(arr[k]<arr[j]){
                tmp = arr[j];
                arr[j] = arr[k];
                arr[k] = tmp;
            }
        }
    }
    
    printf("%d", arr[i-1]);
    
    return 0;
    
}
