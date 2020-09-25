//Classification: #default/n/BO/PAE/aA+aS/v/lc/rp+cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: if 'buf' contains 'a' character, program will write there an int value via cast operation. 
//As max bound in the loop is '7',  buffer will be overrun in case when 'a' is eighth character.

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char buf[10];
	int i, *p = &i;
	fgets (buf, 9, stdin);
	for (i = 0; i<=7; i++) {
		if (buf[i] == 'a') {
			p = (int*)(&buf[i]);
			*p = 12345;
			break;
		}
	}
	
	printf ("%d", *p);
	
	return 0;
}
