//Classification: n/ZD/aS/A(v,c)/rc/rp
//Written by: Sergey Pomelov

int recursion(int argr) {
	if (argr > 1) {
		return (argr);
	}
	argr++;
	return (recursion(argr));
}

int main(void) {
	int a = 1,b;

	a = 0;

	while ((a < 4)) {
		a++;
		b = 1 / (recursion(a) - 3);
	}

	return 0;
}
