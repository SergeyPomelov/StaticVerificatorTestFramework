//Classification: p/ZD/aS/A(v,c)/rc/ln
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

		b = 1 / (recursion(a)) ;

	return 0;
}
