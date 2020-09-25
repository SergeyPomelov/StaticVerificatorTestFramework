//Classification: #default/p/ZD/AE/aS+dS/D(v)/lc/cd+rp
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int main(void) {
	const int c = 10;
	int a = c, b = c;
	int *p = &a;
	int i;
	for (i = 0; i < c; i++) {
		(*p)--;
		b--;
	}
	if (b != 0)
		return 1 / *p;
	return 0;
}
