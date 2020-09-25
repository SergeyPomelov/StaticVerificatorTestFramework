//Classification: #default/p/ZD/AE/aA/D(A(v, c))/fr/rp
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int f() {
	return 1;
}

int main(int argc, char *argv[]) {
	int a[10];
	int i, c;
	for (i = 0; i < 10; i++) {
		a[i] = f();
	}
	c = 1 / a[i];
	return c;
}
