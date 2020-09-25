//Classification: n/DEC/AIC/aS/A(A(v,v),A(v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include<stdio.h>
  
int main(void) 
{ 
    int a;
    int b;
    scanf("%d ",&b);
	printf("%d ",b);
	if ((b<0)&&((a=b)==b)) {
		printf("%d ",a);
        printf("%d ",b);
		return 1; 
    } 
	printf("%d",a);
	return 0; 
} 
