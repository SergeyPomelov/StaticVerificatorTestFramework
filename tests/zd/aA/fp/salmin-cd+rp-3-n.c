// n/ZD/aA/D(A(v, c))/fp/cd+rp

int f(int a[]) {
	if (a[1] != 0)
		return 1 / a[0];
	return 0;
}

int main(int argc, char *argv[]) {
	int a[10];
	int i;
	for (i = 0; i < 10; i++) {
		a[i] = 0;
	}
	a[1] = 1;
	int c = f(a);
	return c;
}
