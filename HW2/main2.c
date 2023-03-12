#include <stdio.h>

int main(){
	FILE  *fp= fopen("main2.c", "r+"), *fpw = fopen("main2.txt", "w+");
	int c, line_ct = 1;
	
	fprintf(fpw,"01 ");
    while ( fread(&c, 1, 1, fp) == 1)
        c == '\n' ? fprintf(fpw,"\n%02d ", ++line_ct) : fprintf(fpw,"%c", c);
	fclose(fp);
	fclose(fpw);
	return 0;
}
