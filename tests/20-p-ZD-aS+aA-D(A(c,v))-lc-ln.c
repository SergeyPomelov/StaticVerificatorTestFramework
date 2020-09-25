//   p/ZD/aS+aA/D(A(c,v))/lc/ln
//   warning #39: division by zero;

int main(void)
{
int *p, a[2], b;
p = a;
a[1] = 1;
b = 1 / p[1];
return 0;
}
