//Classification: #default/n/BO/AE/aS/D(A(v))/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	int* a;
	int b;
	int i;
	int c;
	if((a = (int*)malloc(32*sizeof(int)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	for(c=8,i=0;(i<17)&&(c>i*2);c++,i++) {
		a[c+i] = 2*i; 
		printf("%d",a[c+i]);
	}
	free(a);
	return 0;
}
