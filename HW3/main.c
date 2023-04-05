#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct lotto_record {
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
}lotto_record_t;

int return_serialNumber(){
    int serial_number = 0;
    FILE *ptr = fopen("record.bin", "r+");
    if(ptr == NULL)
        return 0;
    lotto_record_t tmp;
    while(fread(&tmp, sizeof(lotto_record_t), 1, ptr)){
        serial_number++;
    }
    fclose(ptr);
    return serial_number;
}

lotto_record_t buyLotto(int num, int serial_number){
    srand(time(NULL));
	int tm, same = 0, lotto[5][7], tmp[6];
	lotto_record_t lotto_r;
	
	char file_name[23];
	printf("%d\n", serial_number);
	sprintf(file_name, "lotto[%05d].txt", serial_number);
	FILE* fp = fopen(file_name, "w+");
	fprintf(fp, "===========lotto649=========\n");
	fprintf(fp, "===========No.%05d=========\n= ", serial_number);
	
	time_t curtime;
	time(&curtime);
	struct tm* info = localtime(&curtime);
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
			lotto_r.lotto_set[i][j] = tmp[j];
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
	lotto[num][0] = -1;
	for(int i = num;i<5;i++)
		fprintf(fp, "=[%d]: -- -- -- -- -- -- -- =\n", i+1);
	fprintf(fp, "===========CGU@CSIE=========");
	
	lotto_r.receipt_id = serial_number;
	lotto_r.receipt_price = 100*num;
    strcpy(lotto_r.receipt_time, asctime(info));
    
    fclose(fp);
    return lotto_r;
}

void printLotto(lotto_record_t lotto, int* code){
    printf("\n彩券 NO.%d \n", lotto.receipt_id);
    printf("售出時間 %s", lotto.receipt_time);
    for(int i = 0;i<5;i++){
        if(*code == 1){
            printf("號碼:");
            for(int j = 0;j<7;j++){
                if(lotto.lotto_set[i][j]<10)
                    printf("0");
                printf("%d ", lotto.lotto_set[i][j]);
            }
            printf("\n");
        }
        *code++;
    }
}

void redemption(){
    int arr[3], i;
    
    printf("請輸入三個中獎號碼:");
    for(i = 0;i<3;i++)
        scanf("%d", &arr[i]);
    
    printf("輸入中獎號碼為:");
    for(i = 0;i<3;i++){
        if(arr[i]<10)
            printf("0");
        printf("%d ", arr[i]);
    }
    
    int Win = 0, any = 0, code[5] = {0 ,0 ,0, 0, 0};
    FILE *ptr = fopen("record.bin", "r+");
    lotto_record_t tmpf;
    while(fread(&tmpf, sizeof(lotto_record_t), 1, ptr)){
        for(int qw = 0;qw<tmpf.receipt_price/100;qw++){
            for(int we = 0;we<7;we++){
                for(int er = 0;er<3;er++){
                    if(arr[er] == tmpf.lotto_set[qw][we]){
                        Win = 1;
                        code[qw] = 1;
                    }
                }
            }
        }
        if(Win == 1){
            if(any == 0){
                printf("\n以下為中獎彩券:\n");
                any = 1;
            }
            printLotto(tmpf, code);
            Win = 0;
            for(int qw = 0;qw<5;qw++)
                code[qw] = 0;
        }
    }
    if(any == 0)
        printf("\n很遺憾您並未中獎 😭");
    fclose(ptr);
}

void record(lotto_record_t lotto){
    FILE *fp = fopen("record.bin", "a+");
    fwrite(&lotto, sizeof(lotto_record_t), 1, fp);
    fclose(fp);
}

int main(){
	int num, serial_number;
	lotto_record_t lotto_;
	printf("歡迎光臨長庚樂透彩購買機台🤑\n請問您要購買幾組 : ");
	scanf("%d", &num);
	if(num == 0)
	    redemption();
	else{
	    serial_number = return_serialNumber();
	    lotto_ = buyLotto(num, serial_number+1);
	    printf("%s", lotto_.receipt_time);
	    record(lotto_);
	}
}
