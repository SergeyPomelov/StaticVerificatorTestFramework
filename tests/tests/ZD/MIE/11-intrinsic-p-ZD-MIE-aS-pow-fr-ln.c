//Classification: #intrinsic/p/ZD/MIE/aS/pow/fr/ln
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
	printf("%f",func(pow(1,-1.7E+308)));
	return 0;
}
