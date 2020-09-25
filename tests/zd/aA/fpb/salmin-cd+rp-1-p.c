// n/ZD/aA/D(A(v, c))/fpb/cd+rp

void f(int a[]) {
	int i;
	for (i = 0; i < 10; i++)
		a[i] = 0;
}

int main(int argc, char *argv[]) {
	int a[10];
	int i, c;
	f(a);
	if (a[0] != 0) {
		c = 1 / a[3];
	} else {
		return 0;
	}
	return c;
}
