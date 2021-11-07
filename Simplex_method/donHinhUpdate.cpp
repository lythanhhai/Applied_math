#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void nhapMaTranA(float arr[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "nhap arr[" << i << "][" << j << "]" << endl;
            cin >> arr[i][j];
        }
    }
}
void nhapVectoB(float b[], int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << "nhap b[" << i << "]" << endl;
        cin >> b[i];
    }
}

void nhapVectoC(float c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap c[" << i << "]" << endl;
        cin >> c[i];
    }
}

void timHeSo(float heSo[], float arr[][100], float c[], int m, int n)
{
    int count = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[j][i] != 0)
            {
                count++;
                // break;
            }
        }
        if (count == 1)
        {
            // if(index >= m)
            // {
            //     break;
            // }
            heSo[index] = c[i];
            index++;
            count = 0;
        }
        else
        {
            count = 0;
        }
    }
    // test
    // cout << "heso" << endl;
    // for(int i = 0; i < m; i++)
    // {
    //     cout << heSo[i] << " ";
    // }
    // cout << endl;
}

void tinhDelta(float delta[], float arr[][100], float b[], float c[], float heSo[], int n, int m)
{
    // tính tổng của delta
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += heSo[j] * arr[j][i];
        }

        delta[i] = sum - c[i];
        if (delta[i] < 0)
        {
            delta[i] = 0;
        }
    }
    // test
    // cout << "delta2" << delta[1] << endl;
    // cout << "heso0" << heSo[0] << endl;
    // cout << "heso1" << heSo[1] << endl;
    // cout << "arr0" << arr[0][1] << endl;
    // cout << "arr1" << arr[1][1] << endl;
    // cout << "c1" << c[1] << endl;

    // cout << "delta" << endl;
    // for(int i = 0; i < n ; i++)
    // {
    //     cout << delta[i] << " ";
    // }
    // cout << endl;
}

float timFMin(float heSo[], float arr[][100], float b[], float c[], float delta[], int m, int n, float fmin)
{
    // Aik
    int count = 0;
    int checkArr = 0;
    int checkVoNghiem = 0;
    // tìm cột max
    float maxDelta = 0;
    int indexMax = 0;
    // tìm hàng min
    float MaxArr = 1000000;
    int indexMaxArr = 1000000;
    fmin = 0;
    for (int i = 0; i < m; i++)
    {
        fmin += heSo[i] * b[i];
    }
    // cout << fmin << endl;
    //  xét delta
    int checkDelta = 0;
    for (int i = 0; i < n; i++)
    {
        if (delta[i] <= 0)
        {
            checkDelta++;
        }
    }

    if (checkDelta == n)
    {
        count++;
        cout << endl;
        cout << "ket qua la" << endl;
        cout << "gia tri min la " << fmin << endl;
        //return fmin;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if (delta[i] > 0 && arr[j][i] > 0)
                // {
                //     if (maxDelta < delta[i])
                //     {
                //         maxDelta = delta[i];
                //         indexMax = i;
                //     }
                //     checkVoNghiem++;
                // }
                if (delta[i] > 0)
                {
                    if (arr[j][i] > 0)
                    {
                        checkVoNghiem++;
                        if (maxDelta < delta[i])
                        {
                            maxDelta = delta[i];
                            indexMax = i;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (MaxArr > ((float)b[i] / (float)arr[i][indexMax]) && arr[i][indexMax] > 0)
            {
                MaxArr = (float)b[i] / (float)arr[i][indexMax];
                indexMaxArr = i;
            }
        }
        if (checkVoNghiem <= 0)
        {
            count++;
            cout << endl;
            cout << "Ket qua la" << endl;
            cout << "phuong trinh vo nghiem" << endl;
            //return -1000000000;
        }
        else
        {
            // thay thế heSo
            heSo[indexMaxArr] = c[indexMax];

            // update b
            for (int i = 0; i < m; i++)
            {
                if (i == indexMaxArr)
                {
                    b[i] = (float)b[i] / (float)arr[i][indexMax];
                }
                else
                {
                    b[i] = b[i] - ((float)b[indexMaxArr] / (float)arr[indexMaxArr][indexMax]) * (float)arr[i][indexMax];
                }
            }
            // update arr
            //cout << 
            float arrCopy[m][n];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == indexMaxArr)
                    {
                        arrCopy[indexMaxArr][j] = (float)arr[indexMaxArr][j] / (float)arr[indexMaxArr][indexMax];
                    }
                    else
                    {
                        arrCopy[i][j] = arr[i][j] - ((float)arr[indexMaxArr][j] / (float)arr[indexMaxArr][indexMax]) * (float)arr[i][indexMax];
                    }
                }
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    arr[i][j] = arrCopy[i][j];
                }
            }
        }
    }
    tinhDelta(delta, arr, b, c, heSo, n, m);

    // test/debug
    // cout << "heso" << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     cout << heSo[i] << " ";
    // }
    // cout << endl;
    // cout << "A" << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << "B" << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // cout << "delta" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << delta[i] << " ";
    // }
    // cout << endl;

    if (count == 0)
    {
        timFMin(heSo, arr, b, c, delta, m, n, fmin);
    }
    else
    {
    }
    // timFMin(heSo, arr, b, c, delta, m, n, fmin);
}

int main()
{
    int m;
    int n;
    cout << "nhap m" << endl;
    cin >> m;
    cout << "nhap n" << endl;
    cin >> n;
    float array[m][100];
    nhapMaTranA(array, m, n);
    float b[m];
    nhapVectoB(b, m);
    float c[n];
    nhapVectoC(c, n);
    float heSo[m];
    timHeSo(heSo, array, c, m, n);
    float delta[n];
    tinhDelta(delta, array, b, c, heSo, n, m);
    float fmin = 0;
    timFMin(heSo, array, b, c, delta, m, n, fmin);
    cout << endl;
    cout << "delta" << endl;
    for(int i = 0; i < n ; i++)
    {
        cout << delta[i] << " ";
    }
    cout << endl;
}