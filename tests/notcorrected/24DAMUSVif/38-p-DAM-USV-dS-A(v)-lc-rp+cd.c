//Classification: p/DAM/USV/dS/A(v)/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) {
int c = 1;
int *p;
int j;
p = (int*)malloc(sizeof(int));
if (p==NULL) {printf("malloc error");return 1;}
for(j=1; j<100; j++)
  if ((&c)!=(NULL)) *p = 1;
free(p);
printf("%d",c);
return 0;
}
