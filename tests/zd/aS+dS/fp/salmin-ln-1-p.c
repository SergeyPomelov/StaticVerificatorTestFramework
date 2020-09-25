// p/ZD/aS+dS//fp/ln

int f(int *p) {
	return 1 / *p;
}

int main(void) {
	int a = 1;
	return f(&a);
}
