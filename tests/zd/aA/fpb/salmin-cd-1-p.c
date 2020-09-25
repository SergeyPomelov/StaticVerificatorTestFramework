// p/ZD/aA/D(A(v, c))/fpb/cd

void f(int a[]) {
	a[0] = 5;
	a[7] = 0;
	a[3] = 1;
}

int main(int argc, char *argv[]) {
	int a[10];
	int i, c;
	f(a);
	if (a[0] != 5) {
		c = 1 / a[7];
	} else {
		c = 1 / a[3];
	}
	return c;
}
