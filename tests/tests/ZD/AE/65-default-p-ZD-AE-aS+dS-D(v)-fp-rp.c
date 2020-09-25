//Classification: #default/p/ZD/AE/aS+dS/D(v)/fp/rp
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int f(int *p, int c) {
	int i;
	for (i = 0; i < c; i++) {
		(*p)--;
	}
	return 1 / *p;
}

int main(void) {
	int a = 10;
	return f(&a, a + 1);
}
