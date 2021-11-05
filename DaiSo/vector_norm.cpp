#include <stdio.h>
#include <math.h>

int Norm(int norm, int a[], int n)
{
	int kq = 0;
	int b;
	if(norm == 1)
	{
		for(int i = 0 ; i < n ; i++)
		{
			if(a[i] < 0)
			{
				b = -a[i];
			}
			else
			{
				b = a[i];
			}
			kq += b;
		}
		return kq;
	}
	else 
	{
		for(int i = 0 ; i < n ; i++)
		{
			if(a[i] < 0)
			{
				b = pow(-a[i],norm);
			}
			else
			{
				b = pow(a[i],norm);
			}
			kq += b;
		}
		return pow(kq,1/norm);	
	}
		
}
	
int main()
{
	int n;
	printf("Nhap so luong ");
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n ; i++)
	{
		printf("Nhap a[%d] = ",i);
		scanf("%d", &a[i]);
	}	
	int norm;
	printf("Nhap cap norm = ");
	scanf("%c", &norm);
	printf("kq norm cua vector la: %d ",Norm(norm,a,n));
	return 0;	
}



// C2 tính norm vector

// #include<iostream>
// #include<math.h>

// using namespace std;
// class norm
// {
//     public:
//     static int norm_p(int A[], int n, int p);
//     static int norm_two(int A[], int n){
//         int x = 0;
//         for(int i = 0; i< n; i++){
//             x += A[i]*A[i];
//         }
//         return pow(x,1/2);
//     }
//     static int norm_one(int A[], int n){
//         int x = 0;
//          for(int i = 0; i< n; i++){
//             x += A[i];
//         }
//         return x;
//     }
//     static int norm_vo_cung(int A[], int n){
//         int x = INT_MIN;
//          for(int i = 0; i< n; i++){
//             if(x<A[i]) x = A[i];
//         }
//         return x;
//     }
// };
// int main(){
//     int A[] = {2,3,4,5};
//     int B[] ={3,4};
//     cout << norm::norm_one(A, 1);
// }