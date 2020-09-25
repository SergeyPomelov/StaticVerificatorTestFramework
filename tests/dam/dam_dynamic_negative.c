// n/DAM/aS+dA/a(v,c)/lc/ln

#include <stdlib.h>

int main(void) {
	int *p = (int *)malloc(sizeof(int));
	if (p == 0) {
		return 1;
	}
	free(p);
	*p = 0;
	return 0;
}
