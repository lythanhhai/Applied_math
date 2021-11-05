#include<stdio.h>
#include<conio.h>


 
int main()
{
    int i,j,k,n, sign = 1;
    double det = 1; double temp;
    double a[10][10],b[10][10];

    printf("\nCap cua ma tran vuong, n = "); scanf("%d",&n);
 
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            {
                printf("a[%d][%d] = ", i, j);
                scanf("%lf",&a[i][j]);
            }
 
// tính det
    for (i = 0; i < n-1; i++)
        {
            if (a[i][i] == 0)
                {
                    k = i+1;
                    while (k < n && a[k][i] == 0) k++;
                    if (k==n) { printf("\ndet(a) = 0"); break;} 
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
    printf("\ndet(a) = %lf\n",det);
 
 
if (det != 0)
{
    for (i = 0; i < n; i++) // T?o ra b l� ma tr?n don v? d�
        for (j = 0; j < n; j++)
        if (i==j) b[i][j] = 1; else b[i][j] = 0;
 
    for (i = 0; i < n; i++) // X? l� t? h�ng d?u d?n h�ng cu?i
        {
            if (a[i][i] == 0) // N?u g?p ph?n t? tr�n du?ng ch�o ch�nh b?ng 0 th� d?i h�ng
                {
                    k = i+1;
                    while (k < n && a[k][i] == 0) k++;
                    for (j = 0; j < n; j++) // �?i h�ng d� c?a a d�, c? v?i ma tr?n b n?a
                        {
                            temp = a[i][j];
                            a[i][j] = a[k][j];
                            a[k][j] = temp;
                            temp = b[i][j];
                            b[i][j] = b[k][j];
                            b[k][j] = temp;
                        }
                }
 
            temp = a[i][i];
            for (j = i; j < n; j++) a[i][j] /= temp;
            for (j = 0; j < n; j++) b[i][j] /= temp;
 
            for (j = i+1; j < n; j++)
                {
                    temp = -a[j][i];
                    for (k = i; k < n; k++) a[j][k] += temp*a[i][k];
                    for (k = 0; k < n; k++) b[j][k] += temp*b[i][k];
                }
        }// K?t th�c qu� tr�nh Gauss
 
    for (i = n-1; i > 0; i--) // B?t d?u qu� tr�nh Jordan
        for (j = i-1; j >=0; j--)
            {
                temp = -a[j][i];
                for (k = n-1; k >= i; k--)  a[j][k] += temp*a[i][k];
                for (k = 0; k < n; k++) b[j][k] += temp*b[i][k];
            }
 
    for (i = 0; i < n; i++)// In ra ma tr?n b, b�y gi? l� ma tr?n nghich d?o c?a a
        {
            for (j = 0; j < n; j++) printf("%8.3lf\t", b[i][j]);
            printf("\n");
        }
}
else printf("\nKhong co ma tran nghich dao\n");
    getch();
}

// C2 tìm ma trận nghịch đảo
// #include<iostream>
// #include<iomanip>
// using namespace std;
// void nhap(float a[][100],int &n);
// void xuat(float a[][100],int n);
// float det(float a[][100],int n);
// float con(float a[][100],int n,int h,int c);
// void nghichdao(float a[][100],int n);
// int main()
// {
 
//  	int n=2;
// 	float a[100][100];
//     for(int i=0;i<n;i++)
//     {
//     for(int j=0;j<n;j++)
//       {
//         a[i][j] = rand()%(15);
//       }
//  	}
//  xuat(a,n);
//  cout<<"\n-------------------------------\nma tran nghich dao:\n";
//  nghichdao(a,n);
//  system("pause");
// }

// void xuat(float a[][100],int n)
// {
//  for(int i=0;i<n;i++)
//  {
//   cout<<"\n\n";
//   for(int j=0;j<n;j++)
//    cout<<setw(6)<<a[i][j];
//  }
// }
// float det(float a[][100],int n)
// {
//  int i,j,k,dem=0,kt;
//  float b[100],h,kq=1;
//  for(i=0;i<n-1;i++)
//  {
//   if(a[i][i]==0)
//   {
//    kt=0;
//    for(j=i+1;j<n;j++)
//    {
//     if(a[i][j]!=0)
//     {
//      for(k=0;k<n;k++)
//      {
//       float t=a[k][i];
//       a[k][i]=a[k][j];
//       a[k][j]=t;
//      }
//      dem++;kt++;
//      break;
//     }
//    }
//    if(kt==0) return 0;
//   }
//   b[i]=a[i][i];
//   for(j=0;j<n;j++) a[i][j]/=b[i];
//   for(j=i+1;j<n;j++)
//   {
//    h=a[j][i];
//    for(k=0;k<n;k++) a[j][k]=a[j][k]-h*a[i][k];
//   }
//  }
//  b[n-1]=a[n-1][n-1];
//  for(i=0;i<n;i++) kq*=b[i];
//  if(dem%2==0) return kq;
//  return -kq;
// }
// float con(float a[][100],int n,int h,int c)
// {
//  float b[100][100];
//  int i,j,x=-1,y;
//  for(i=0;i<n;i++)
//  {
//   if(i==h) continue;
//   x++;y=-1;
//   for(j=0;j<n;j++)
//   {
//    if(j==c)continue;
//    y++;
//    b[x][y]=a[i][j];
//   }
//  }
//  if((h+c)%2==0) return det(b,n-1);
//  return -det(b,n-1);
// }
// void nghichdao(float a[][100],int n)
// {
//  float b[100][100];
//  for(int i=0;i<n;i++)
//  {
//   for(int j=0;j<n;j++)
//   {
//    b[i][j]=con(a,n,i,j);
//   }
//  }
//  for(int i=0;i<n-1;i++)
//   for(int j=i+1;j<n;j++)
//   {
//    float t=b[i][j];
//    b[i][j]=b[j][i];
//    b[j][i]=t;
//   }
//  float k=det(a,n);
//  for(int i=0;i<n;i++)
//   for(int j=0;j<n;j++)
//    b[i][j]/=k;
//  if(k==0) cout<<"\nkhong co ma tran nghich dao!";
//  else xuat(b,n);
// }