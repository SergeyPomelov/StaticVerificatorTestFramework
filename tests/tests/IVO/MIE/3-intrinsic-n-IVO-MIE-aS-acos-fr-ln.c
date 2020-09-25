//Classification: #intrinsic/n/IVO/MIE/aS/acos/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <math.h>
#include <stdio.h>

#define M_PI_2 1.57079632679489661923

double func(double arg) {
	double b;
	b = 1 / arg;
	return b;
}

int main(void) {
	printf("%f",func(acos(M_PI_2)));
	return 0;
}
