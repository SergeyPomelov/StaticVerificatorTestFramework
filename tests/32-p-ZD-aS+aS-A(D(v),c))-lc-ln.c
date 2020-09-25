//   p/ZD/aS+aS/A(D(v),c)/lc/ln
//  warning #39: division by zero;

int main(void)
{
int a = 0, b = 1, c, *p=&a;
c = b / (*p - 1);
return 0;
}
