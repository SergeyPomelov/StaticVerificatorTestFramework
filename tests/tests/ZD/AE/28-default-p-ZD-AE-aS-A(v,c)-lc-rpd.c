//Classification: #default/p/ZD/AE/aS/A(v,c)/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) {
	int a, b, i;
	for(a=0,i=1;(i<5)&&(a>-1);a++,i++) {
		b = 1 / (a - i);
		printf("%i ",b);
	}
	return 0;
}
