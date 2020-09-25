//Classification: n/ZD/aS/A(v,c)/rc/ln
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

		b = 1 / (recursion(a) - 2);

	return 0;
}
