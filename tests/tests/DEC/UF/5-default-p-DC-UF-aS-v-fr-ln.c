//Classification: #default/p/DC/UF/aS/v/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

void f (int i) { 
	i++;
	printf("%i",i); 
	i--;	
	printf("%i",i); 
}

int main ( void ) {
	int a;
	scanf("%i",&a);
	f (a);
   return 0 ;
}
