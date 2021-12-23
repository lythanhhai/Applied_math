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
            cout << "nhap arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }
}
void nhapVectoB(float b[], int m)
{
    for (int i = 0; i < m; i++)
    {
        cout << "nhap b[" << i << "] = ";
        cin >> b[i];
    }
}

void nhapVectoC(float c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap c[" << i << "] = ";
        cin >> c[i];
    }
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
}
void timFMin(float heSo[], float arr[][100], float b[], float c[], float delta[], int m, int n, float fmin)
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
        cout << "ket qua la: " << endl;
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
            cout << "Ket qua la: " << endl;
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

    if (count == 0)
    {
        timFMin(heSo, arr, b, c, delta, m, n, fmin);
    }
    else
    {
    }
}

void setCPha1(float cpha1[], int m, int n)
{
    for(int i = 0 ; i < m + n; i++)
    {
        if(i < n)
        {
            cpha1[i] = 0;
        }
        else 
        {
            cpha1[i] = 1;
        }
    }
}

void timHeSoPha1(float heSoPha1[], int m)
{
    for(int i = 0 ; i < m; i++)
    {
        heSoPha1[i] = 1;
    }
}

void setArrPha1(float arrPha1[][100], float arr[][100], int m, int n)
{
    float arrT[m][m];
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            cout << "arrT[" << i << "][" << j << "] = ";
            cin >> arrT[i][j];
        }
    }
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m + n; j++)
        {
            if(j < n)
            {
                arrPha1[i][j] = arr[i][j];
            }
            else 
            {
                arrPha1[i][j] = arrT[i][j - n];
            }
        }
    }
}

void tinhDeltaPha1(float deltaPha1[], float arrPha1[][100], float b[], float cpha1[], float heSoPha1[], int n, int m)
{
    // tính tổng của delta
    float sum = 0;
    for (int i = 0; i < n + m; i++)
    {
        sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += heSoPha1[j] * arrPha1[j][i];
        }

        deltaPha1[i] = sum - cpha1[i];
        if (deltaPha1[i] < 0)
        {
            deltaPha1[i] = 0;
        }
    }
    
}

float timFMinPha1(float heSoPha1[], float arrPha1[][100], float b[], float cpha1[], float deltaPha1[], int arrContainCot[], float c[], int m, int n, float fmin1)
{
    // Aik
    int count = 0; // xét điều kiện đệ quy
    int count1 = 0; // xét điều kiện cho pha2
    int checkArr = 0;
    int checkVoNghiem = 0;
    // tìm cột max
    float maxDelta = 0;
    int indexMax = 0;
    // tìm hàng min
    float MaxArr = 1000000;
    int indexMaxArr = 1000000;
    fmin1 = 0;
    for (int i = 0; i < m; i++)
    {
        fmin1 += heSoPha1[i] * b[i];
    }
    // cout << fmin << endl;
    //  xét delta
    int checkDelta = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (deltaPha1[i] <= 0)
        {
            checkDelta++;
        }
    }

    if (checkDelta == n + m)
    {
        count++;
        count1++;
        //cout << endl;
        //cout << "ket qua la" << endl;
        //cout << "gia tri min la " << fmin1 << endl;
        //return fmin;
    }
    else
    {

        for (int i = 0; i < n + m; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (deltaPha1[i] > 0)
                {
                    if (arrPha1[j][i] > 0)
                    {
                        checkVoNghiem++;
                        if (maxDelta < deltaPha1[i])
                        {
                            maxDelta = deltaPha1[i];
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
            if (MaxArr > ((float)b[i] / (float)arrPha1[i][indexMax]) && arrPha1[i][indexMax] > 0)
            {
                MaxArr = (float)b[i] / (float)arrPha1[i][indexMax];
                indexMaxArr = i;
            }
        }
        if (checkVoNghiem <= 0)
        {
            count++;
            cout << endl;
            cout << "Ket qua la: " << endl;
            cout << "phuong trinh vo nghiem" << endl;
            //return -1000000000;
        }
        else
        {
            // thay thế heSo
            heSoPha1[indexMaxArr] = cpha1[indexMax];
            for(int i = 0; i < m ; i++)
            {
                if(i == indexMaxArr)
                {
                    arrContainCot[indexMaxArr] = indexMax; 

                }
            }
            // update b
            for (int i = 0; i < m; i++)
            {
                if (i == indexMaxArr)
                {
                    b[i] = (float)b[i] / (float)arrPha1[i][indexMax];
                }
                else
                {
                    b[i] = b[i] - ((float)b[indexMaxArr] / (float)arrPha1[indexMaxArr][indexMax]) * (float)arrPha1[i][indexMax];
                }
            }
            // update arr
            //cout << 
            float arrCopy[m][n + m];
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n + m; j++)
                {
                    if (i == indexMaxArr)
                    {
                        arrCopy[indexMaxArr][j] = (float)arrPha1[indexMaxArr][j] / (float)arrPha1[indexMaxArr][indexMax];
                    }
                    else
                    {
                        arrCopy[i][j] = arrPha1[i][j] - ((float)arrPha1[indexMaxArr][j] / (float)arrPha1[indexMaxArr][indexMax]) * (float)arrPha1[i][indexMax];
                    }
                }
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n + m; j++)
                {
                    arrPha1[i][j] = arrCopy[i][j];
                }
            }
        }
    }
    tinhDeltaPha1(deltaPha1, arrPha1, b, cpha1, heSoPha1, n, m);


    if (count == 0)
    {
        // tiếp tục pha 1
        timFMinPha1(heSoPha1, arrPha1, b, cpha1, deltaPha1, arrContainCot, c, m, n, fmin1);

    }
    else
    {
        if(count1 == 0)
        {

        }
        else 
        {
            int count2 = 0;// điều kiện kiểm tra xem còn t không
            for(int i = 0; i < m ; i++)
            {
                if(heSoPha1[i] > 0)
                {
                    count2++;
                }
            }
            if(count2 > 0)
            {
                cout << "phuong trinh vo nghiem" << endl;
            }
            else 
            {
                float arrPha2[m][100];
                for(int i = 0 ; i < m ; i++)
                {
                    for(int j = 0 ; j < n ; j++)
                    {
                        arrPha2[i][j] = arrPha1[i][j];
                    }
                }
                float cpha2[n];
                for(int i = 0 ; i < n ; i++)
                {
                    cpha2[i] = c[i];
                }
                float bpha2[m];
                for(int i = 0 ; i < m ; i++)
                {
                    bpha2[i] = b[i];
                }
                float heSoPha2[m];
                for(int i = 0 ; i < m ; i++)
                {
                    // if(arrContainCot[i] != -1)
                    // {
                        heSoPha2[i] = c[arrContainCot[i]];
                    //}
                }
                float delta[n];
                tinhDelta(delta, arrPha2, bpha2, cpha2, heSoPha2, n, m);
                // qua pha 2
                timFMin(heSoPha2, arrPha2, bpha2, cpha2, delta, m, n, fmin1);
            }
        }
    }

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

    int arrContainCot[m];
    for(int i = 0;i < m ; i++)
    {
        arrContainCot[i] = -1; 
    }
    float cpha1[m + n];
    setCPha1(cpha1, m, n);
    float heSoPha1[m];
    timHeSoPha1(heSoPha1, m);
    float arrPha1[m][100];// m + n
    setArrPha1(arrPha1, array, m, n);
    float deltaPha1[m + n];
    tinhDeltaPha1(deltaPha1, arrPha1, b, cpha1, heSoPha1, n, m);
    float fmin1;
    timFMinPha1(heSoPha1, arrPha1, b, cpha1, deltaPha1, arrContainCot, c, m, n, fmin1);
    cout << endl;
    // cout << "delta" << endl;
    // for(int i = 0; i < n ; i++)
    // {
    //     cout << delta[i] << " ";
    // }
    cout << endl;
}