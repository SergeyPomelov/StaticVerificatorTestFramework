#include <stdio.h>
#include <math.h>

typedef struct {
	int Re, Im;
} complex;

float module(complex z)
{
	return pow( pow(z.Re, 2)+pow(z.Im, 2) , 0.5 );
}
