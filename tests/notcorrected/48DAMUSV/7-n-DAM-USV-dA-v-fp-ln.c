//Classification: n/DAM/USV/dA/v/fp/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) {
if ((q=(int*)malloc(100*sizeof(int)))==NULL) 
{printf("malloc error"); 
return NULL;
}
else {free(q);  return q;}
}

int main(void) {
int c =1;
int* p = &c;
p = func(p);
*(p+c) = 1;
printf("%d",c);
return 0;
}
