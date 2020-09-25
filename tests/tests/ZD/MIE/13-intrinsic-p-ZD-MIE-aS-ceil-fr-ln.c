//Classification: #intrinsic/p/ZD/MIE/aS/ceil/fr/ln
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
	printf("%f",func(ceil(1.1)));
	return 0;
}
