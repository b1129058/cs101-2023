#include <stdio.h>

int multiplication(int i, int j){
    if(j == 9 && i == 9){
        printf("%d*%d=%d ", i, j, i*j);
        return 0;
    }
    if(i != 9 && j == 10){
        j = 1;
        printf("\n");
        multiplication(i+1, j);
    }else{
        printf("%d*%d=%d ", i, j, i*j);
        multiplication(i, j+1);
    }
}

int main(){
    multiplication(1, 1);
    return 0;
}
