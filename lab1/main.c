#include <stdio.h>
#include <stdlib.h>

int main ()
{
  FILE* fp;
  int a[] = { 1, 2, 3 };
  int arr_read[5];
  //char b[] = "ABC";
  //float c[] = { 1.1, 1.2, 1.3 };

  if ((fp = fopen ("a.bin", "wb+")) == NULL)
    {
      exit (1);
    }
  fwrite (a, sizeof (a), 1, fp);
  
  
  fseek(fp, 0, SEEK_SET);
  fread(arr_read, sizeof(arr_read), 1, fp);


  return 0;
}
