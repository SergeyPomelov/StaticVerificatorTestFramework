//Classification: #intrinsic/n/ZD/MIE/aS/exp/fr/ln
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
	printf("%f",func(exp(-1.7E+308)));
	return 0;
}
