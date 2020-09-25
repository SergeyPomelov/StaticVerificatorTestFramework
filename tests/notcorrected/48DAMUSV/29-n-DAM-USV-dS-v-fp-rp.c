//Classification: n/DAM/USV/dS/v/fp/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) {
int j = 1;
if ((q=(int*)malloc(sizeof(int)))==NULL) 
{printf("malloc error"); 
return NULL;
}
else {free(q);  return q;}
}

int main(void) {
int a = 1;
int c = 1;
int j = 1;
int* p = &c;
 for (j;j<100;j++) p = func(p);
*p = 1;
printf("%d",c);
return 0;
}
