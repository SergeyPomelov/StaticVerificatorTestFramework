//Classification: n/DEC/AIC/aS/A(A(v,c),A(v,c))/fr/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include<stdio.h>

int func(int a, int b)
{

if ((b<0)&&((a=b)==b)){
	return a + 1;
    } else {
	return a + 2;
	}
}

int main(void) 
{ 
    int a;
	int b;
    scanf("%d",&a);
	printf("%d ",a);
	    scanf("%d",&b);
	printf("%d ",b);
	a = func(a,b);
	printf("%d ",a);
	scanf("%d",&a);
	return 0; 
} 