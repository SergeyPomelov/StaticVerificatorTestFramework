//Classification: p/DAM/USV/dS/v/fp/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) {
if ((q=(int*)malloc(sizeof(int)))==NULL) 
{printf("malloc error"); 
return NULL;
}
else {return q;}
}

int main(void) {
int c = 1;
int* p = &c;
p = func(p);
*p = 1;
printf("%d",c);
return 0;
}
