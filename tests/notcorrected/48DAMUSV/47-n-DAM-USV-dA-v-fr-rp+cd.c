//Classification: n/DAM/USV/dA/v/fr/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(void) {
int j = 1;
int* q;if ((q=(int*)malloc(100*sizeof(int)))==NULL) 
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
 for (j;j<100;j++) if (p!=NULL) p = func();
*p = 1;
printf("%d",c);
return 0;
}
