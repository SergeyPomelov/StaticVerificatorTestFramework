//Classification: #default/n/ZD/AE/aS+dS/v/fr/ln
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int f(int *p) {
	return *p - 1;
}

int main(void) {
	int a = 1;
	return 1 / f(&a);
}
