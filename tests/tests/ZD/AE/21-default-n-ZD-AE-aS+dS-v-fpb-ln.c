//Classification: #default/n/ZD/AE/aS+dS/v/fpb/ln
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

void f(int *p) {
	*p = 0;
}

int main(void) {
	int a = 1;
	f(&a);
	return 1 / a;
}
