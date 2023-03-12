#include <stdio.h>

int main(){
	FILE  *fp= fopen("main.c", "r+"), *fpw = fopen("main2.txt", "w+");
	int c, line_ct = 1;
	
	fprintf(fpw,"01  ");
	while ((c = getc(fp)) != EOF)
	    c == '\n' ? fprintf(fpw,"\n%02d  ", ++line_ct) : fprintf(fpw,"%c", c);
	fclose(fp);
	fclose(fpw);
	return 0;
}
