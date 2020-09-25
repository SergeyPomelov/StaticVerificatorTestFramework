//Classification: #default/p/BO/AE/aS/D(A(v))/lc/rpd+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: b!=0 error

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
	scanf("%d",&b);
	for(c=0,i=0;(i<15)&&(c<15);c++,i++) {
		if (b==0) {
			a[b+i] = 2*i; 
			printf("%d",a[b+i]);
		} else {
			a[i] = i; 
			printf("%d",a[i]);
		}
	}
	free(a);
	return 0;
}
