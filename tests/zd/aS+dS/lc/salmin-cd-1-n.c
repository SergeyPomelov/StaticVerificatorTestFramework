// n/ZD/aS+dS//lc/cd

int main(void) {
	int a = 0;
	int b = 3;
	int *p;
	if (b == 3) {
		p = &a;
	} else {
		p = &b;
	}
	return 1 / *p;
}
