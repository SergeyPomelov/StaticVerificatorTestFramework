//Classification: #default/p/ZD/AE/aS+dS/v/rc/ln
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

void f(int *p, int c) {
	c--;
	if (c <= 0)
		return;
	*p = c;
	f(p, c);
}

int main(void) {
	int a = 10;
	f(&a, 10);
	return 1 / a;
}
