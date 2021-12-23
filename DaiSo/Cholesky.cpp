#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
#include "../Eigen/Eigenvalues"


void nhap(float matrix[][100], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "nhap a[" << i << "][" << j << "]: ";
			cin >> matrix[i][j];
		}
	}
}

void xuat(float matrix[][100], int n, int m)
{
	cout << "Ma tran goc: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
bool kiemTraMaTranVuong(float matrix[][100],int n, int m)
{
	if(n == m)
	{
		return 1;
	}	
	return 0;
}	
bool kiemTraDoiXung(float matrix[][100], int n, int m)
{
	// kiem tra
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(matrix[i][j] == matrix[j][i])
			{
				
			}
			else 
			{
				return 0;
			}
		}	
	}
	return 1;
}	

void kiemTraMaTranXDD(Eigen::MatrixXd matrix,int n, int m)
{
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		printf("nhap matrix[%d][%d] = ", i, j);
	// 		scanf("%f", matrix(i, j));
	// 	}
    // }
	// Eigen::EigenSolver<Eigen::MatrixXd > s(matrix);
	// printf("eigenvalues: \n");
	// printf("%f", s.eigenvalues()(0));
}

void maTranCheoTren(float matrix[][100],int n, int m)
{
	float L[100][100];
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			L[i][j] = 0;
		}
	}
	for(int j = 0 ; j < n ; j++)
	{
		for(int i = j ; i < m ; i++)
		{
			if(i == j)
			{
				sum = 0;
				for(int k = 0 ; k < j ; k++)
				{
					sum += pow(L[i][j],2);
				}	
				L[i][j] = sqrt(matrix[i][j] - sum);
			}	
			else 
			{
				sum = 0;
				for(int k = 0 ; k < j ; k++)
				{
					sum+= L[i][k] * L[j][k];
				}
				L[i][j] = (matrix[i][j] - sum)/L[j][j];
			}	
		}	
	}
    
    cout << "Ma tran cheo tren: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << L[i][j] << " ";
		}
		cout << endl;
	}


	float L1[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			L1[i][j] = L[j][i];
		}
	}
    
    cout << "Ma tran cheo duoi: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << L1[i][j] << " ";
		}
		cout << endl;
	}
}	

int main()
{
	float matrix[100][100];
	int n;
	cout << "Nhap n = ";
	cin >> n;
	nhap(matrix, n, n);
	xuat(matrix, n, n);
	Eigen::MatrixXd A(n,n);
	kiemTraMaTranXDD(A, n, n);
	kiemTraMaTranVuong(matrix, n, n);
	kiemTraDoiXung(matrix, n, n);
	maTranCheoTren(matrix,n,n);
}

// C2 cholesky

// float phanra(int[] a, int[] l, int n)
// {
//     for(int k = 1; k <= n; k++)
//     {
//        l[k][k] = a[k][k];
//        if(l[k][k] == 0)
//        return 0;
//        else{
//        for(int i = k+1; i <= n;i++)
//        {
//            l[i][k] = a[i][k];
//            u[k][i] = a[k][i]/l[k][k];
//            u[i][k] = 0;
//            l[k][i] = 0;
//        }
//        for(int i = k+1; i <= n; i++)
//        for(int j = k+1; j <= n; j++)
//        a[i][j] = a[i][j] - l[i][k]*u[k][j];       
//     }
//   }
// }

// int main()
// {
// 	int arr[10][10];
// 	int n = 2;
// 	int m = 3;
//     for(int i=0;i<n;i++)
//     {
//     for(int j=0;j<m;j++)
//       {
//         arr[i][j] = rand()%(15);
//       }
//  	}
// 	for(int i=0;i<n;i++)
//     {
//     	for(int j=0;j<m;j++) cout<<arr[i][j]<< " " ;
//     	cout<<"\n";
//     }
// 	cout << Norm(arr, n, m, 3);
// }