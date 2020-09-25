//Classification: #default/p/BO/PWF/dS/v/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: Printf is called with a format from a table. This is not a defect.

#include <stdio.h>
 
char *fmts[] = {
    "<%s>\n",
    "[%s]\n",
};
 
int main(int argc, char **argv)
{
    char *userstr; 
	int idx; 
	if (argc < 2)
		return 1;
	userstr = argv[1];
    idx = (userstr[0] == '!');
    printf(fmts[idx], userstr);  
    return 0;
}
