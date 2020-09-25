//Classification: #intrinsic/p/ZD/MIE/aS/fmod/fr/ln
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
	printf("%f",func(fmod(1.7,0.8)));
	return 0;
}
