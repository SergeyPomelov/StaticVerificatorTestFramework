//Classification: #default/p/BO/AE/aS/D(A(v))/lc/rpd+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: b!=0 error

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
	for(c=0,i=0;(i<15)&&(c<15);c++,i++) {
		if (b==0) {
			a[b+c+i] = i*2.2; 
			printf("%f",a[c+b+i]);
		} else {
			a[i] = i*1.1; 
			printf("%f",a[i]);
		}
	}
	free(a);
	return 0;
}
