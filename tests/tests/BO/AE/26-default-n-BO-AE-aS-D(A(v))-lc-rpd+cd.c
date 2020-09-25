//Classification: #default/n/BO/AE/aS/D(A(v))/lc/rpd+cd
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
	for(c=0,i=0;(i<17)&&(i<17);c++,i++) {
		if (b==0) {
			a[c+b+i] = 2*i; 
			printf("%d",a[c+b+i]);
		} else {
			a[i] = i; 
			printf("%d",a[i]);
		}
	}
	free(a);
	return 0;
}
