//Classification: #default/p/ZD/AE/aS+dS/D(v)/fp/ln
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int f(int *p) {
	return 1 / *p;
}

int main(void) {
	int a = 1;
	return f(&a);
}
