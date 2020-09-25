//   p/DAM/aS+aS/v/lc/ln
//  Warning#13: Dereference of possibly null pointer

int main(void)
{
int *p, a, b = 3;
p = &b;
if (1 == 1) {
int c = 10;
b=c;
}
a = *p;
return 0;
}
