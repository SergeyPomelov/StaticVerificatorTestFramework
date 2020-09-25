//Classification: #default/p/ZD/AE/aS+dS/v/fpb/ln
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

void f(int *p) {
	*p = 1;
}

int main(void) {
	int a = 0;
	f(&a);
	return 1 / a;
}
