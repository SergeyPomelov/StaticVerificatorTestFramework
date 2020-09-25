//Classification: #default/n/ZD/AE/aS+aS/A(D(v))/lc/ln
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int main(void)
{
int a, b = 1, *p = &b, *p1 = &b;
a = 1 / (*p - *p1) ;
return 0;
}
