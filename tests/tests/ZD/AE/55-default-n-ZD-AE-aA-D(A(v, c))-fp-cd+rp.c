//Classification: #default/n/ZD/AE/aA/D(A(v, c))/fp/cd+rp
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int f(int a[], int d) {
	if (d == 0)
		return 1 / a[0];
	return 0;
}

int main(int argc, char *argv[]) {
	int a[10];
	int i, d = 0;
	for (i = 0; i < 10; i++) {
		a[i] = 0;
	}
	int c = f(a, d);
	return c;
}
