//Classification: n/DEC/AIC/aS/A(A(v,v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include<stdio.h>
  
int main(void) 
{ 
    int a;
    int b;
    scanf("%d",&a);
    scanf("%d",&b);
	if ((a<b)&&(a=b)) {
		printf("%d ",a);
        printf("%d ",b);
		return 1; 
    } 
	printf("%d %d ",a,b);
	return 0; 
} 
