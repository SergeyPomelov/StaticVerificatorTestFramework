//Classification: #default/p/BO/PWF/dS/v/fr/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: Printf is called with a format from a table. This is not a defect.

#include <stdio.h>
 
char *fmts[] = {
        "<%s>\n",
        "[%s]\n",
};
 
void proc(char *str)
{
    int idx; 
    idx = (str[0] == '!');
    printf(fmts[idx], str);    /* OK */
}
 
int main(int argc, char **argv)
{
    char *userstr; 
    if(argc > 1) {
		userstr = argv[1];
            proc(userstr);
    }
    return 0;
}
