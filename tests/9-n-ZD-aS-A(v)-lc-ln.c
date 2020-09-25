//   n/ZD/aS/A(v)/lc/ln
//   warning #39: division by zero;

int main(void)
{
int a = 1, b = a;
a = 1 / (b - a);
return 0;
}
