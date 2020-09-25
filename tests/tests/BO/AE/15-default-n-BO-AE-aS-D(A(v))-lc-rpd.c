//Classification: #default/n/BO/AE/aS/D(A(v))/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	float* a;
	int b;
	int i;
	int c;
	if((a = (float*)malloc(32*sizeof(float)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	scanf("%d",&b);
	for(c=0,i=0;(i<17)&&(c>-1);c++,i++) {
		if (b==0) {
		a[b+c+i] = i*1.1;
		printf("%f",a[b+i+c]);
		} 
	}
	free(a);
	return 0;
}
