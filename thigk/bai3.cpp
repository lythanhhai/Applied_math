#include<iostream>
#include<math.h>
using namespace std;
const int e = 2.71828;
// hàm f(x)
double cost(int x)
{
    return pow(pow(e, x) - 2/pow(e, x), 2);
}

// đạo hàm f'(x)
double grad(int x)
{
    return 2 * pow(e, 2*x) - 8 * pow(e, -2 * x);
}

double grad(double alpha, int x0, double gra = 1 * pow(10, -3), int loop = 100)
{
    double arr[loop];
    arr[0] = x0;
    double min = arr[0];
    for(int i = 0 ; i < loop; i++)
    {
        arr[i + 1] = arr[i] - alpha * grad(arr[i]);
        if(min > arr[i + 1])
        {
            min = arr[i + 1];
        }
        if(abs(grad(i + 1)) < gra)
        {
            break;
        }
    }
    // for(int i = 0 ; i < 100 ; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    return min;
}

int main()
{
    cout << "gia tri nho nhat la: " << endl;
    cout << grad(0.1, 10);
}
