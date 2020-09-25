//   p/ZD/aS+aS/A(D(v))/lc/ln
//   warning #39: division by zero;

int main(void)
{
int a, b = 1, *p = &b;
a = 1 / *p ;
return 0;
}
