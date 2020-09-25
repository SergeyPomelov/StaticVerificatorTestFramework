// p/ZD/aS+dS//fpb/ln

void f(int *p) {
	*p = 1;
}

int main(void) {
	int a = 0;
	f(&a);
	return 1 / a;
}
