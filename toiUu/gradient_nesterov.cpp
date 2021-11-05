#include<iostream>
#include<math.h>
using namespace std;

// hàm f(x)
double cost(int x)
{
    return pow(x, 2) + 10 * sin(x);
}

// đạo hàm f'(x)
double grad(int x)
{
    return 2 * x + 10 * cos(x);
}

// momentum
void GD_nesterov(double theta_init, double alpha=0.1,double beta=0.9,int loop = 1000)
{
    double arr[loop];// theta
    arr[0] = theta_init;
    double arr1[loop];// v
    arr[0] = 0;
    double v_new;
    for(int i = 0 ; i < loop; i++)
    {
        arr1[i+1] = arr1[i] * beta + alpha * grad(arr[i] - beta * arr1[i]);
        arr[i+1] = arr[i] - arr1[i+1];
        //arr[i + 1] = arr[i] - alpha * grad(arr[i]);
        arr1[i] = arr1[i+1];
    }
    // for(int i = 0 ; i < loop ; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    double min = arr[0];
     for(int i = 0 ; i < loop ; i++)
    {
        if(min > arr[i+1])
        {
            min = arr[i+1];
        }
        //cout << arr[i] << " ";
    }
    cout << endl;
    cout << "min = " << min << endl;
}

// // gradient discent
// double* myGD1(double alpha, int x0, double gra = 1 * pow(10, -3), int loop = 100)
// {
//     double arr[loop];
//     arr[0] = x0;
//     for(int i = 0 ; i < loop; i++)
//     {
//         arr[i + 1] = arr[i] - alpha * grad(arr[i]);
//         if(abs(grad(i + 1)) < gra)
//         {
//             break;
//         }
//     }
//     double min = arr[0];
//     for(int i = 0 ; i < loop ; i++)
//     {
//         if(min > arr[i+1])
//         {
//             min = arr[i+1];
//         }
//         //cout << arr[i] << " ";
//     }
//     cout << endl;
//     cout << "min = " << min << endl;
//     //return arr;
// }

int main()
{
    cout << cost(1);
    //myGD1(5, 0.1);
    GD_nesterov(5);
    // for(int i = 0 ; i < 1000 ; i++)
    // {
    //     cout << grad(0.1, 10)[i] << endl;
    // }
    //cout << grad(0.1, 10)[0] << endl;
    //grad(0.1, 10);
}
