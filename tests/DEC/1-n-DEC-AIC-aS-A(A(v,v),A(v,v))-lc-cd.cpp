//Classification: n/DEC/AIC/aS/A(A(v,v),A(v,v))/lc/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include<iostream>

using namespace std;
  
int main(void) 
{ 
	bool bF = true;
    bool bM = true;
    int a = 1;
    int b = 1;
    cin >> bF;
    cin >> bM;
    cin >> a;
    cin >> b;
	if ((a<b)&&(bF=bM)) {
		cout << bF << '\n'; 
        cout << bM << '\n';
		return 1; 
    } 
	printf("%d %d",a,b);
	return 0; 
} 
