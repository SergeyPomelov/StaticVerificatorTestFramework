//Classification: #intrinsic/n/BO/SIO/aA/strlen/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment: buffer overflow using strlen

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	char buf[27];
	int i;
	
	for (i = 0; i<26; i++) {
		buf[i] = 'a'+i;
	}
		
	buf[strlen(buf)] = '\0';
	
	printf ("%s", buf);	
	
	return 0;
}
