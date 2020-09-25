//Classification: p/IVO/IVV/aA/D(A(v))/lc/rp+cd
//Written by: Pomelov Sergey
//Reviewed by:
//Comment: b<1e3. false positive death test

#include <stdio.h>

int main(void) 
{
	int a[32];
	int b;
	int i;
	scanf("%d",&b);
	for(i=1;i<32;i++) { 
		if ((b*b+1)<0) {
			if(b<1e7 && b>-1e7) {
				printf("%d ",*(a+i));		
			}
		} else {
			*(a+i) = b+i;
			printf("%d ",*(a+i));
		}
	}
    scanf("%d",&b);
	return 0;
}
