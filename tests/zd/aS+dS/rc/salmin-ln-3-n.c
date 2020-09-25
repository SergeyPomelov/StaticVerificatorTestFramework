// n/ZD/aS+dS//rc/ln

void f(int *p, int c) {
	c--;
	if (c < 0)
		return;
	*p = c;
	f(p, c);
}

int main(void) {
	int a = 10;
	f(&a, 100);
	return 1 / a;
}
