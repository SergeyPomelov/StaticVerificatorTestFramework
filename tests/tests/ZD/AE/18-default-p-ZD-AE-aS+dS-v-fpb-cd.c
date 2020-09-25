//Classification: #default/p/ZD/AE/aS+dS/v/fpb/cd
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

void f(int *p, int *c) {
	*p = 0;
	*c = 1;
}

int main(void) {
	int a = 1, c = 0;
	f(&a, &c);
	if (c != 1)
		return 1 / a;
	return 0;
}
