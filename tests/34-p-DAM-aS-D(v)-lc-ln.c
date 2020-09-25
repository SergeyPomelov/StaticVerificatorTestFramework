//   p/DAM/aS/D(v)/lc/ln
//  warning #592: variable "p" is used before its value is set

int main(void)
{

int a, *p=&a;
*p = 1;

return 0;
}
