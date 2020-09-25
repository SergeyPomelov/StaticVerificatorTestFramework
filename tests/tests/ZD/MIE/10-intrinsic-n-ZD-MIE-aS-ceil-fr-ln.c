//Classification: #intrinsic/n/ZD/MIE/aS/ceil/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <math.h>
#include <stdio.h>

float func(float arg) {
	float b;
	b = 1 / arg;
	return b;
}

int main(void) {
	printf("%f",func(ceil(-1e-34)));
	return 0;
}
