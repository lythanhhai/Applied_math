#include <stdio.h>
#include<iostream>
#include <math.h>

using namespace std;

void nhapMaTranA(float arr[][100], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "nhap arr[" << i << "][" << j << "]" << endl;   
            cin >> arr[i][j];
        } 
    }
       
}
void nhapVectoB(float b[], int m)
{
    for(int i = 0; i < m; i++)
    {
        cout << "nhap b[" << i << "]" << endl;   
        cin >> b[i];
    }
}

void nhapVectoC(float c[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "nhap c[" << i << "]" << endl;   
        cin >> c[i];
    }
}

void timHeSo(float heSo[], float arr[][100], float c[], int m, int n)
{
    int count = 0;
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[j][i] != 0)
            {
                count++;
                //break;
            }
        } 
        if(count == 1)
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
    cout << "heso" << endl;
    for(int i = 0; i < m; i++)
    {
        cout << heSo[i] << endl;
    }
}

void tinhDelta(float delta[], float arr[][100], float b[], float c[], float heSo[], int n, int m)
{
    
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            delta[i] += heSo[j] * arr[j][i];
        }
    }
    for(int i = 0 ; i < n; i++)
    {
        delta[i] = delta[i] - c[i];
    }
    for(int i = 0 ; i < n; i++)
    {
        if(delta[i] < 0)
        {
            delta[i] = 0;
        }
    }
    

    cout << "delta" << endl;
    for(int i = 0; i < n ; i++)
    {
        cout << delta[i] << endl;
    }
        
}

float timFMin(float heSo[], float arr[][100],float b[], float c[], float delta[], int m, int n, int fmin)
{
     // Aik
    int checkArr = 0;
    int checkVoNghiem = 0;
    float maxDelta = 0;
    int indexMax = 0;
    float MaxArr = 1000000;
    int indexMaxArr = 1000000;


    for(int i = 0 ; i < m; i++)
    {
        fmin += heSo[i] * b[i];
    }
    // xét delta 
    int checkDelta = 0;
    for(int i = 0 ; i < n; i++)
    {
        if(delta[i] <= 0)
        {
            checkDelta++;
        }
    }
   
    if(checkDelta == n)
    {
        return fmin;
    }
    else 
    {
        
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                if(delta[i] > 0 && arr[j][i] > 0)
                {
                    if(maxDelta < delta[i])
                    {
                        maxDelta = delta[i];
                        indexMax = i;
                    }
                    checkVoNghiem++;
                }
                
            }
        }
        for(int i = 0 ; i < m ; i++)
        {
            if(MaxArr > (b[i] / arr[i][indexMax]) && arr[i][indexMax] > 0)
            {
                MaxArr = arr[i][indexMax];
                indexMaxArr = i;
            }       
        }
        if(checkVoNghiem <= 0)
        {
            return 0.001;
        }
        else 
        {
            // thay thế heSo
            heSo[indexMaxArr] = c[indexMax];

            // update b
            for(int i = 0 ; i < m; i++)
            {
                    if(i == indexMaxArr)
                    {
                        b[i] = b[i] / arr[i][indexMax];
                    }
                    else 
                    {
                        b[i] = b[i] -  (b[i] / arr[indexMaxArr][indexMax]) * c[indexMax];
                    }
            }
            // update arr
            for(int i = 0 ; i < m; i++)
            {
                for(int j = 0; j < n ; j++)
                {
                    if(i == indexMaxArr)
                    {
                        arr[i][j] = arr[i][j] / arr[i][indexMax];
                    }
                    else 
                    {
                        arr[i][j] = arr[i][j] -  (arr[indexMaxArr][j] / arr[indexMaxArr][indexMax]) * c[indexMax];
                    }
                }
            }
        }
        
    }
    tinhDelta(delta, arr, b, c, heSo, n, m);
    cout << "A" << endl;
            for(int i = 0 ; i < m; i++)
            {
                for(int j = 0; j < n ; j++)
                {
                    cout << arr[i][j] << endl;
                }
            }
            cout << "B" << endl;
            for(int i = 0 ; i < m; i++)
            {
                cout << b[i] << endl;
            }
    //timFMin(heSo, arr, b, c, delta, m, n, fmin);
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
}