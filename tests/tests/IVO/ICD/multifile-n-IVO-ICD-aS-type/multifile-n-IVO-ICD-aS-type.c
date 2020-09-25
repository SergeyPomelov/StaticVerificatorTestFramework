//Classification: #multifile/n/IVO/ICD/aS/type
//Written by: Igor Eremeev
//Reviewed by:
//Comment: 

#include <stdio.h>

typedef struct {
	float Re, Im;
} complex;

float module (complex z);	

int main(void)
{
	complex z;
	z.Im = 3.5;
	z.Re = 4.7;
	printf ("%f", module(z));
	return 0;
}
