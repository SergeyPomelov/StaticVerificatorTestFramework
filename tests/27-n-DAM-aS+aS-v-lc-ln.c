//   n/DAM/aS+aS/v/lc/ln
//  Warning#13: Dereference of possibly null pointer

int main(void)
{
int *p, a;
if (1 == 1) {
int b = 3;
p = &b;
}
a = *p;
return 0;
}
