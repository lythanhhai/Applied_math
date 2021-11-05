#include<iostream>
#include<math.h>
using namespace std;

// hàm f(x)
double cost(int x)
{
    return pow(x, 2) + 5 * sin(x);
}

// đạo hàm f'(x)
double grad(int x)
{
    return 2 * x + 5 * cos(x);
}

double* grad(double alpha, int x0, double gra = 1 * pow(10, -3), int loop = 100)
{
    double arr[loop];
    arr[0] = x0;
    for(int i = 0 ; i < loop; i++)
    {
        arr[i + 1] = arr[i] - alpha * grad(arr[i]);
        if(abs(grad(i + 1)) < gra)
        {
            break;
        }
    }
    for(int i = 0 ; i < 100 ; i++)
    {
        cout << arr[i] << " ";
    }
    return arr;
}

int main()
{
    cout << cost(1);
    // for(int i = 0 ; i < 1000 ; i++)
    // {
    //     cout << grad(0.1, 10)[i] << endl;
    // }
    //cout << grad(0.1, 10)[0] << endl;
    grad(0.1, 10);
}
