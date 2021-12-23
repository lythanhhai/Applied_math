#include <iostream>
#include <stdio.h>
using namespace std;

int GCD(int a, int b)
{
	if(b == 0)
    {
         return a;
    } 
	return GCD(b, a % b);
}

int main(){
	int a = 2, b = 3;
	cout <<"uoc chung lon nhat la: " << GCD(a, b) << endl;
    int a1 = 3, b1 = 5;
	cout <<"uoc chung lon nhat la: " << GCD(a1, b1) << endl;
    int a2 = 4, b2 = 7;
	cout <<"uoc chung lon nhat la: " << GCD(a2, b2) << endl;
	return 0;
}