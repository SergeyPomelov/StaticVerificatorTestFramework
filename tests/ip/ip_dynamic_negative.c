// n/IP/aS+dA/a(v,c)/lc/ln

#include <stdlib.h>

int main(void) {
	int *p = (int *)malloc(sizeof(int));
	*p = 0;
	free(p);
	return 0;
}
