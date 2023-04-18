#include <stdio.h>
#include <time.h>
int ct = 1;
int hanoi(int n, char A, char B, char C){
    FILE* fp = fopen("hanoi.txt", "a+");
    struct tm* info;
	time_t curtime;
	time(&curtime);
	info = localtime(&curtime);
    if(n == 1){
        fprintf(fp, "%d  (", ct++);
        for(int i = 0;i<24;i++)
            fprintf(fp, "%c", asctime(info)[i]);
        fprintf(fp, ")");
        fprintf(fp, "%dP form %c to %c\n", n , A, C);
        fclose(fp);
        
        return 0;
    }else{
        hanoi(n-1, A, C, B);
    
        fprintf(fp, "%d  (", ct++);
        for(int i = 0;i<24;i++)
            fprintf(fp, "%c", asctime(info)[i]);
        fprintf(fp, ")");
        fprintf(fp, "%dP form %c to %c\n", n , A, C);
        fclose(fp);
        
        hanoi(n-1, B, A, C);
    }
}

int main(){
    ct = 1;
    hanoi(7, 'A', 'B', 'C');
    return 0;
}
