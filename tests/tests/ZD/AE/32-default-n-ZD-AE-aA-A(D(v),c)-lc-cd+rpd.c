//Classification: #default/n/ZD/AE/aA/A(D(v),c)/lc/cd+rpd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int main(void) {
	int a[2], b, i;
	a[0] = 4;
	a[1] = 4;
	if (a[1] == a[0]) {
		for(a[0]=0,i=0;(i<5)&&(a[0]>-1);a[0]++) {
		i = a[0]+1;
		b = 1 / (a[1] - i);
		printf("%i ",b);
		}
	}
	return 0;
}
