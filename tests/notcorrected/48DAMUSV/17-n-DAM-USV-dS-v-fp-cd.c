//Classification: n/DAM/USV/dS/v/fp/cd
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
else {free(q);  return q;}
}

int main(void) {
int c =1;
int* p = &c;
if (func(p)!=NULL)
p = func(p);
*p = 1;
printf("%d",c);
return 0;
}
