//Classification: p/ZD/aA/A(D(v),c)/fp/cd+rp
//Written by: Sergey Pomelov

int func(int arg[2]) {
int b;
	if (arg[0] == 0) {
          while ((arg[1] < 3)) {
		     arg[1]++;
		     b = 1 / (arg[1] - 2);
	      }
    }
	return 0;
}

int main(void) {
	int a[2];
	a[0]=0;
	a[1]=2;
	func(a);
return 0;
}
