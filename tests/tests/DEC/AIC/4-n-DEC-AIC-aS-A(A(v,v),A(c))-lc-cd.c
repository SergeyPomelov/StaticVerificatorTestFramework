//Classification: #default/n/DEC/AIC/aS/A(A(v,v),A(c))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include<stdio.h>

int main(void) 
{ 
    int a;
    scanf("%d",&a);
	printf("%d",a);
	if ((a<0)&&((a=0)==0)) {
		printf("%d",a);
		return 1; 
    } 
	printf("%d",a);
	return 0; 
} 
