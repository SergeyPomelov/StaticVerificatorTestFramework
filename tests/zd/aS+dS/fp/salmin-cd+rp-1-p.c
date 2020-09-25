// p/ZD/aS+dS//fp/cd+rp

int f(int *p, int c) {
	int i;
	for (i = 0; i < c; i++) {
		if (*p > 0)
			(*p)--;
	}
	return 1 / *p;
}

int main(void) {
	int a = 10;
	return f(&a, a);
}
