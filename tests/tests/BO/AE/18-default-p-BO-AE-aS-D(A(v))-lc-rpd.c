//Classification: #default/p/BO/AE/aS/D(A(v))/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	int* a;
	int i;
	int c;
	if((a = (int*)malloc(32*sizeof(int)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	for(c=0,i=0;(i<15)&&(c>-1);c++,i++) {
		a[i] = i; 
		printf("%d",a[i]);
	}
	free(a);
	return 0;
}
