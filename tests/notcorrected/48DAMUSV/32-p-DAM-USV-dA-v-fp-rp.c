//Classification: p/DAM/USV/dA/v/fp/rp
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
else {return q;}
}

int main(void) {
int a = 1;
int c = 1;
int j = 1;
int* p = &c;
 for (j;j<100;j++) if (func(p)!=NULL) {p = func(p);
*(p+c) = 1;
free(p);}
printf("%d",c);
return 0;
}
