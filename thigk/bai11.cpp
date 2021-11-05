#include <iostream> 
using namespace std;

long long sumUoc(long long N)
{
    long long sum = 0;
    for(int i = 1 ; i <= N ; i++)
    {
        if(N % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

long long soCacUocSo(long long N)
{
    long long count = 0;
    for(int i = 1 ; i <= N; i++)
    {
        if(N % i == 0)
        {
            count++;
        }
    }
    return count;
}


long long multipleUoc(long long N)
{
    long long multiple = 1;
    for(int i = 1 ; i <= N/2; i++)
    {
        if(N % i == 0)
        {
            multiple *= i;
            multiple %= 1000000009;
        }
    }
    return (multiple % 1000000009) * N ;
}


int main()
{
    long long N;
    cout << "nhap N: ";
    cin >> N;
    cout << "tich cac uoc N la = " << multipleUoc(N) << endl;
}
