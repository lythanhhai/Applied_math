#include <iostream>
#include <math.h>



	
int main(int argc, char** argv) {



		int n;
		printf("nhap n");
		scanf("%d",&n);
		int kq;
		for(int i = 1 ; i < n ; i++)
		{
			if(soHoanHao(i))
			{
				printf("%d  ",i);
			}
		}
}
//		int kq = 1;
//		while(nguyenTo(n) == false)
//		{
//			for(int i = 2 ; i < n; i++)
//			{
//				if(nguyenTo(i) && n%i==0)
//				{
//					n = n / i;
//					break;
//					}
//				else 
//				{
//					continue;
//				}	
//			}	
//			kq = kq * n;
//			printf("%d\n",n);
//		}
//		

			
//}


//typedef int VECTOR[MAX];
//
//void PrimeFactors(int n, VECTOR S, int &k);
//
//int main()
//
//{
//
//    int  k;
//
//    int F[MAX];
//
//    int n =30;
//
//    PrimeFactors(n, F, k);
//
//    for (int i = 0; i<=k; i++)
//
//        printf("%d ", F[i]);
//
//    return 0;
//
//}
//
//void PrimeFactors(int n, VECTOR S, int &k)
//
//{
//
//    k = 0;
//
//    S[k] = n;
//
//    for (int i=2; i*i<=n; i++){
//
//        while (n%i==0){
//
//            k++;
//
//            S[k] = i;
//
//            n = n/i;
//
//        }      
//
//    }
//
//    if (n>1) S[++k]=n;
//
//}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	bool nguyenTo(int n) {
        if (n < 2)
		{
			return false;

		}
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0)
				return false;
		}
		return true;
}

bool soHoanHao(int i)
{		int kq = 0;
     	for(int j = 1 ; j <= i / 2 ; j++)
		{
			if(i % j == 0)
			{
				kq+=j;
			}
		}
		if(kq == i)
		{
		return true;
		
		}
		return false;
}

