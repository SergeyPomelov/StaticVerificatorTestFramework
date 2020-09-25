//Classification: #intrinsic/n/ZD/MIE/aS/fmod/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <math.h>
#include <stdio.h>

int main(void) {
	double a;
	double b;
	a = fmod(1.6,0.8);
    b = 1 / a;
	printf("%f",b);
	return 0;
}
