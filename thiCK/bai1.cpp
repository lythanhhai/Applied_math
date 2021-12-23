#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
 
int main() {
    int n;
    int i;
    cout << "Nhap n = ";
    cin >> n;
    
    cout << "Ket qua khi phan tich thua so la: ";
    for (i = 2; i <= n; i++)
    {
        while(n % i == 0) {
            cout << i << ".";
            n /= i;
        }
    }
    cout << endl;
    return 0;
}