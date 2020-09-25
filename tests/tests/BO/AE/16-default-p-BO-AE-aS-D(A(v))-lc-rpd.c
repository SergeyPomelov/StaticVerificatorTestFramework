//Classification: #default/p/BO/AE/aS/D(A(v))/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	float* a;
	int i;
	int c;
	if((a = (float*)malloc(32*sizeof(float)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	for(c=0,i=0;(i<15)&&(c>-1);c++,i++) {
		a[i+c] = i*1.1;
		printf("%f",a[i+c]);		
	}
	free(a);
	return 0;
}
