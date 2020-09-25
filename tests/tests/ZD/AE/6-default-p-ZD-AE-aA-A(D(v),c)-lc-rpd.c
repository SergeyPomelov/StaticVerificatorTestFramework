//Classification: #default/p/ZD/AE/aA/A(D(v),c)/lc/rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) {
	int a[2], b, i;
	a[0] = 0;
	a[1] = 0;
	for(a[0]=0,i=1;(i<5)&&(a[0]>-1);a[0]++,i++) {
		b = 1 / (a[0] - i);
		printf("%i ",b);
	}
	return 0;
}
