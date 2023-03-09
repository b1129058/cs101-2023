#include <stdio.h>

int main(){
	FILE  *fp, *fpw;
	fp = fopen("main2.c", "r+");
	fpw = fopen("main2.txt", "w+");
	int c;
	
    while ( (c = getc(fp)) != EOF)
        fprintf(fpw, "%c", c);
	fclose(fp);
	fclose(fpw);
	return 0;
}
