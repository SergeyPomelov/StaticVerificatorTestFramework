//Classification: #intrinsic/n/IVO/MIE/aS/acos/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <math.h>
#include <stdio.h>

double func(double arg) {
	double b;
	b = 1 / arg;
	return b;
}

int main(void) {
	printf("%f",func(acos(1.1)));
	return 0;
}
