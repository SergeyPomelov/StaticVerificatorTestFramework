//Classification: #default/p/ZD/AE/aS+aS/A(D(v),c)/lc/ln
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int main(void)
{
int a = 0, b = 1, c, *p=&a;
c = b / (*p - 1);
return 0;
}
