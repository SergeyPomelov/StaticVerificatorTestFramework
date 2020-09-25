//Classification: n/DAM/USV/dA/A(v)/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) {
int c = 1;
int *p;
p = (int*)malloc(100*sizeof(int));
if (p==NULL) {printf("malloc error");return 1;}
if ((&c)!=(NULL)) free(p);
*(p+c) = 1;
printf("%d",c);
return 0;
}
