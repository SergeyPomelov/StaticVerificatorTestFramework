//    n/DAM/aS/D(v)/fp+fr/ln
//   warning #592: variable "x" is used before its value is set

int main(void)
{

int a,*p = &a;

extern int getVal (int *p);

   return getVal (p);

return 0;
}
