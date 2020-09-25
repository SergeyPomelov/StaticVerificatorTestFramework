// p/IP/aS+dA/a(v,c)/lc/cd

#include <stdlib.h>

int main(void) {
	int *p = (int *)malloc(sizeof(int));
	if (p == 0) {
		return 0;
	}
	*p = 0;
	free(p);
	return 0;
}
