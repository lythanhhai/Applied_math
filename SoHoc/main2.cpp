#include <stdio.h>
int prime(int n);
void Eratosthenes(int n);
int main()
{
    int n = 20;
    Eratosthenes(n);
    return 0;
}
void Eratosthenes(int n)
{
    int arr[n];
    for (int i =0; i<n; i++) {
        arr[i] = 0;
    }
    for (int i = 2; i*i<=n; i++) {
        if (arr[i]==0) {
            for (int j = i*2; j<=n; j+=i) {
               arr[j] = 1;
            }
        }
    }
    for (int i=2; i<=n; i++) {
        if (arr[i]==0) {
            printf("%d ",i);
        }
    }
}
int prime(int n)
{
    for (int i =2; i*i<n; i++) {
        if (n%i ==0) {
            return 0;
        }
    }
    return 1;
}

	
