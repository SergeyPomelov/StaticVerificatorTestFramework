//Classification: #intrinsic/n/ZD/MIE/aS/cos/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <math.h>
#include <stdio.h>

#define M_PI_2 1.57079632679489661923

int main(void) {
	double a;
	double b;
	a = cos(M_PI_2);
    b = 1 / a;
	printf("%f",b);
	return 0;
}
