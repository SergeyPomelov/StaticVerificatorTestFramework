//Classification: #intrinsic/p/ZD/MIE/aS/pow/fpr/ln
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
	printf("%f",func(pow(1,2)));
	return 0;
}
