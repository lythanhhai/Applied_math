#include <stdio.h>
#include <math.h>

int Norm(int norm, int a[][100],int n, int m)
{
	int kq = 0;
	int b;
	int max = 0;
		if(norm == 1)
		{
			for(int i = 0 ; i < m ; i++)
			{
				kq = 0;
				for(int j = 0 ; j < n; j++)
				{
					if(a[j][i] < 0)
					{
						b = -a[j][i];
					}
					else
					{
						b = a[j][i];
					}
					kq += b;			
				}
				if(max < kq)
				{
					max = kq;
				}
			}
				
			
			return max;
		}
		else 
		{
			for(int i = 0 ; i < n ; i++)
			{
				kq = 0;
				for(int j = 0 ; j < m; j++)
				{
					if(a[i][j] < 0)
					{
						b = -a[i][j];
					}
					else
					{
						b = a[i][j];
					}
					kq += b;			
				}
				if(max < kq)
				{
					max = kq;
				}
			}
				
			
			return max;
			
		}	
	
		
}
	
void nhapMaTran(int a[][100], int n, int m)
{
	for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
      {
         printf("a[%d][%d] = ", i, j);
         scanf("%d", &a[i][j]);
      }
}

int main()
{
	int n,m;
	printf("Nhap so luong hang ");
	scanf("%d", &n);
	printf("Nhap so luong cot ");
	scanf("%d", &m);
	int a[n][100];	
	nhapMaTran(a,n,m);
	int norm;
	printf("Nhap cap norm = ");
	scanf("%d", &norm);
	printf("kq norm cua ma tran la: %d ", Norm(norm, a, n, m));
	return 0;	
}

