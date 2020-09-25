//Classification: #default/n/DEC/AIC/aS/A(A(v))/fr/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include<stdio.h>

int func(int a)
{
if ((a<0)&&(a=0)) {
	return a + 1;
    } else {
	return a + 2;
	}
}

int main(void) 
{ 
    int a;
    scanf("%d",&a);
	printf("%d ",a);
	a = func(a);
	printf("%d ",a);
	return 0; 
} 
