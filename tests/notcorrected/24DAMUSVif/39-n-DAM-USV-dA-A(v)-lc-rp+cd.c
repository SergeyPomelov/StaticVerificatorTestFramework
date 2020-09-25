//Classification: n/DAM/USV/dA/A(v)/lc/rp+cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int j;
int main(void) {
int c = 1;
int *p;
p = (int*)malloc(100*sizeof(int));
if (p==NULL) {printf("malloc error");return 1;}
for(j=1; j<100; j++){
      if ((&c)!=(NULL)) free(p);
}
*(p+j) = 1;
printf("%d",c);
return 0;
}
