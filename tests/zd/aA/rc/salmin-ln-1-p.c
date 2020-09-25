// p/ZD/aA/D(A(v, c))/rc/ln

int f(int a[], int i) {
	i--;
	if (i < 0)
		return;
	a[i] = i;
	f(a, i);
}

int main(int argc, char *argv[]) {
	int a[10];
	int i, c;
	f(a, 10);
	c = 1 / a[1];
	return c;
}
