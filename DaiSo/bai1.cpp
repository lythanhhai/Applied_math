#include<stdio.h>
#include<conio.h>
 
int main()
{
    int i,j,k,n, sign = 1;
    double det = 1; double temp;
    double a[10][10];
    
    printf("\nCap cua ma tran vuong, n = ");
    scanf("%d",&n);
 
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            {
                printf("a[%d][%d] = ", i, j);
                scanf("%lf", &a[i][j]);
            }
 
    for (i = 0; i < n-1; i++)
    {
            if (a[i][i] == 0) 
            {
                k = i + 1;
                while (k < n && a[k][i] == 0) k++;
                if (k == n) { printf("\ndet(a) = 0"); break;}
                for (j = i; j < n; j++)
                {
                    temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
                sign = -sign; 
                }
                for (j = i+1; j < n; j++)
                {
                    temp = -a[j][i]/a[i][i];
                    for (k = i+1; k < n; k++)   a[j][k] += temp*a[i][k]; 
                }
            det *= a[i][i];
    }
 
    det *= a[n-1][n-1]; 
    printf("\ndet(a) = %lf\n", det);
 
}


// Nhan voi phan tu cuoi cheo chinh nua l� xong
