//Classification: #default/n/ZD/AE/aS+dS//lc/cd
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

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
