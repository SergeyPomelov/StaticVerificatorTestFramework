//Classification: #default/p/BO/PWF/dS/v/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:	Printf is called with static format string.


#include <stdio.h>
 
void proc(char *fmt, char *str)
{
        printf(fmt, str);                            /* true */
}
 
int main(int argc, char **argv)
{
    char *userstr;
	if (argc < 2)
		return 1;
	userstr = argv[1];
    if(userstr[0] == '!')
        proc("<%s>", userstr);
    else 
        proc("[%s]", userstr);
    return 0;
}
