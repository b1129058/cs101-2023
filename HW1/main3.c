/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    char a[] = "ABC123";
    char tmp[] = "";
    int shift = 6, i = 0, j;
    
    int len = sizeof(a)/sizeof(a[0])-1;
    
    shift = (shift + len)%len;

    for(i = shift;i<len; i++){
        printf("%c", a[i]);
    }
    
    for(i = 0;i<shift;i++){
        printf("%c", a[i]);
    }
    
    return 0;
}
