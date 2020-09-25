//Classification: n/ZD/aS/A(v,c)/rc/cd+rp
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
	
	if (a == 0) {
		a = recursion (a);
	}
	
	while ((a < 4)) {
		a++;
		b = 1 / (a - 3);
	}

	return 0;
}
