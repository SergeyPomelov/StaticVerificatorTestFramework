// n/ZD/aS+dS//fr/ln

int f(int *p) {
	return *p - 1;
}

int main(void) {
	int a = 1;
	return 1 / f(&a);
}
