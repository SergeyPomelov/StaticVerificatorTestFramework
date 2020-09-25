// p/DAM/aS+dA/a(v,c)/lc/ln

#include <stdlib.h>

int main(void) {
	int *p = (int *)malloc(sizeof(int));
	if (p == 0) {
		return 1;
	}
	*p = 0;
	free(p);
	return 0;
}
