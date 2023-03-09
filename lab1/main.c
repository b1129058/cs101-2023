#include <stdio.h>
#include <stdlib.h>

int main ()
{
  FILE* fp;
  int a[] = { 1, 2, 3 };
  int arr_read[5];
  fp = fopen ("a.bin", "wb+");
  fwrite (a, sizeof (a), 1, fp);
  fseek(fp, 0, SEEK_SET);
  fread(arr_read, sizeof(arr_read), 1, fp);
  for(int i = 0;i<3;i++)
    printf("%d", arr_read[i]);
  return 0;
}
