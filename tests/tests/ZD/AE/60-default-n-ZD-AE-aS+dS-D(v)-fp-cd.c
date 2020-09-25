//Classification: #default/n/ZD/AE/aS+dS/D(v)/fp/cd
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int f(int *p, int c) {
	if (c == 0)
		return 1 / *p;
	return 0;
}

int main(void) {
	int a = 0;
	return f(&a, 0);
}
