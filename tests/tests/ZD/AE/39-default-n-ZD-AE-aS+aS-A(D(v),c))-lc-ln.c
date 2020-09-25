//Classification: #default/n/ZD/AE/aS+aS/A(D(v),c))/lc/ln
//Written by: Alexey Salmin
//Reviewed by: Igor Eremeev

int main(void)
{
int a = 1, b = 3, c, *p=&a;
c = b / (*p - 1);
return 0;
}
