#include <stdio.h>

typedef struct person{
    int id;
    char first_name[32];
    char last_name[32];
} person_t;

int main(){
    FILE *wfp = fopen("person.bin", "w+"), *rfp = fopen("person.bin", "r");
    person_t p[5] = {   {1, "IU", "Lee"},
                        {2, "IUU", "Lee"},
                        {3, "IUUU", "Lee"},
                        {4, "IUUUU", "Lee"},
                        {5, "IUUUUU", "Lee"},
        
    }, tmp;
    int i, j = 0;
    
    //write
    for(i = 0;i<5;i++){
        fwrite(p+i, sizeof(person_t), 1, wfp);
    }
    fclose(wfp);
    
    //read
    while(fread(&tmp, sizeof(person_t), 1, rfp)){
        printf("[%d] %d: %s %s\n", j, tmp.id, tmp.first_name, tmp.last_name);
        j++;
    }
    return 0;
}
