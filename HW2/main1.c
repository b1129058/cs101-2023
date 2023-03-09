#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int seed = 10;
	srand(time(NULL));
	int num = 5, tm;
	int same = 0;
	struct tm* info;
	
	printf("歡迎光臨長庚樂透彩購買機台\n請問您要購買幾組 : ");
	scanf("%d", &num);
	printf("已為您購買 %d 組樂透組合輸出至 lotto.txt", num); 
	
	int lotto[5][7], tmp[6];
	FILE* fp;
	
	fp = fopen("lotto.txt", "w+");
	
	
	fprintf(fp, "===========lotto649=========\n= ");
	time_t curtime;
	time(&curtime);
	info = localtime(&curtime);
	fprintf(fp, "%s", asctime(info));
	
	for(int i = 0;i<num;i++){
		same = 1;
		while(same){
			same = 0;
			for(int j = 0;j<6;j++)
				tmp[j] = rand()% (69 - 1 +1) + 1;
			tmp[6] = rand()% (9 - 1 +1) + 1;
			for(int j = 0;j<=6-1;j++){
				for(int k = j+1;k<=6;k++){
					if(tmp[j] == tmp[k]){
						same = 1;
						break;
					}
				}
			}
			
		}
		
		
		for(int j = 0;j<=4;j++){
		    for(int k = j+1;k<=5;k++){
		        if(tmp[j]>tmp[k]){
		            tm = tmp[k];
		            tmp[k] = tmp[j];
		            tmp[j] = tm;
		        }
		    }
		}
		
		for(int j = 0;j<=6;j++){
			lotto[i][j] = tmp[j];
		}
		
	}
	
	for(int i = 0;i<num;i++){
		fprintf(fp, "=[%d]: ", i+1);
		for(int j = 0;j<=6;j++){
			if(lotto[i][j]<=9)
				fprintf(fp, "0");
			fprintf(fp, "%d ", lotto[i][j]);
		}
		fprintf(fp, "=\n");
	}
	for(int i = num;i<5;i++){
		fprintf(fp, "=[%d]: ", i+1);
		for(int j = 0;j<=6;j++){
			fprintf(fp, "-- ");
		}
		fprintf(fp, "=\n");
	}
	fprintf(fp, "===========CGU@CSIE=========");
	
	fclose(fp);

	return 0;
}
