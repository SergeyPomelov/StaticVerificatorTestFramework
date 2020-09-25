//   p/DAM/aS+aS/v/lc/ln
//  warning #592: variable "x" is used before its value is set

int main(void)
{
int *p, b,*p1=&b;
p = p1;
return 0;
}
