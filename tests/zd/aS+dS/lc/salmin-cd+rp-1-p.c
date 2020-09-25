// p/ZD/aS+dS//lc/cd+rp

int main(void) {
	const int c = 10;
	int a = c, b = c;
	int *p = &a;
	int i;
	for (i = 0; i < c; i++) {
		(*p)--;
		b--;
	}
	if (b != 0)
		return 1 / *p;
	return 0;
}
