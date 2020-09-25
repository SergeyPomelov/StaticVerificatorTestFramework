// p/ZD/aS+dS//fr/ln

int f(int *p) {
	return *p - 1;
}

int main(void) {
	int a = 2;
	return 1 / f(&a);
}
