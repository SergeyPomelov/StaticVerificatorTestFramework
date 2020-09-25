// n/ZD/aA/D(A(v, c))/fpb/ln

void f(int a[]) {
	a[7] = 0;
	a[3] = 1;
}

int main(int argc, char *argv[]) {
	int a[10];
	int i, c;
	f(a);
	c = 1 / a[7];
	return c;
}
