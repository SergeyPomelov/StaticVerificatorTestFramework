//Classification: #default/p/BO/PWF/dS/v/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:	Printf is called with static format string.


#include <stdio.h>

int main(int argc, char **argv)
{
    char *userstr;
	if (argc < 2)
		return 1;
	userstr = argv[1];
    if(userstr[0] == '!')
        printf("<%s>", userstr);
    else 
        printf("[%s]", userstr);
    return 0;
}
