// n/ZD/aS+dS//fp/ln

int f(int *p) {
	return 1 / *p;
}

int main(void) {
	int a = 0;
	return f(&a);
}
