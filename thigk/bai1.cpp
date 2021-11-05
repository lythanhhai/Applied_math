#include <iostream> 
using namespace std;

long long sumUoc(long long N)
{
    int sum = 0;
    for(int i = 1 ; i <= N ; i++)
    {
        if(N % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

long long multipleUoc(long long N)
{
    int multiple = 1;
    for(int i = 1 ; i <= N ; i++)
    {
        if(N % i == 0)
        {
            multiple *= i;
        }
    }
    return multiple;
}

int main()
{
    long long N;
    cout << "nhap N: ";
    cin >> N;
    cout << "tong uoc N la = " << sumUoc(N) << endl;
    cout << 1;
}
