#include <iostream>
#include <math.h>
using namespace std;

// hàm f(x)
double cost(int x)
{
    return pow((log(pow(x, 2) + 10) + x - 5), 2) + 2 * x;
}

// đạo hàm f'(x)
double grad(int x)
{
    return (log(pow(x, 2) + 10) + x - 5) * (4 * x + 2 * pow(x, 2) + 20) / (pow(x, 2) + 10) + 2;
}

// hàm tính gradient_discent
double myGradient_Discent(double alpha, int x0, double gra = 1 * pow(10, -5), int loop = 1000)
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
    return min;
}

int main()
{
    cout << "gia tri nho nhat la: ";
    cout << myGradient_Discent(0.1, 0.5) << endl;
}
