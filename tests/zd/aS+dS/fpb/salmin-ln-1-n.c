// n/ZD/aS+dS//fpb/ln

void f(int *p) {
	*p = 0;
}

int main(void) {
	int a = 1;
	f(&a);
	return 1 / a;
}
