// p/ZD/aS+dS//lc/rp

int main(void) {
	int a = 11;
	int *p = &a;
	int i;
	for (i = 0; i < 10; i++)
		*p--;
	return 1 / *p;
}
