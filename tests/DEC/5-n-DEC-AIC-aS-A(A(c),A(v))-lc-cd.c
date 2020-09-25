//Classification: n/DEC/AIC/aS/A(A(c),A(v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include<stdio.h>

int main(void) 
{ 
    int a;
    scanf("%d",&a);
	if (((a=0)==0)&&(a<0)) {
		printf("%d",a);
		return 1; 
    } 
	printf("%d",a);
	return 0; 
} 
