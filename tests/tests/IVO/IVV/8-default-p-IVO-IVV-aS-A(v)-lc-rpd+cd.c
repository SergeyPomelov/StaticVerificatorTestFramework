//Classification: #default/p/IVO/IVV/aS/A(v)/lc/rpd+cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment: b<1e3. many false-positives(tru 1e7 b=999999)

#include <stdio.h>

int main(void) 
{
	int a;
	int b;
	int i;
	int c;
	scanf("%d",&b);
	for(c=0,i=0;(i<5)&&(c>-1);c++,i++) {
		if (((b*b+1)<0) && (b<1e3) && (b>-1e3)) {
				printf("%d ",a);		
		} else {
			a = b+i;
			printf("%d ",a);
		}
	}
	return 0;
}
