// p/ZD/aA/D(A(v, c))/fpb/rp

void f(int a[]) {
	int i;
	for (i = 0; i < 10; i++)
		a[i] = 9 - i;
}

int main(int argc, char *argv[]) {
	int a[10];
	int i, c;
	f(a);
	c = 1 / a[0];
	return c;
}
