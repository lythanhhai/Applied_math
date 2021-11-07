#include <stdio.h>
#include<iostream>
#include <math.h>

using namespace std;
void nhapMaTranA(double arr[][100], int m, int n)
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
void nhapVectoB(double b[], int m)
{
    for(int i = 0; i < m; i++)
    {
        cout << "nhap b[" << i << "]" << endl;   
        cin >> b[i];
    }
}

void nhapVectoC(double c[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "nhap c[" << i << "]" << endl;   
        cin >> c[i];
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
    double arr[m][100];
    nhapMaTranA(arr, m, n);
    double b[m];
    nhapVectoB(b, m);
    double c[n];
    nhapVectoC(c, n);
    cout<<" bat dau";
     double heSo[m];
    for(int i=0;i<m;i++)
    {
        heSo[i]=0;
    }
     int index =0;
    
    for(int i=0;i<n;i++)
    {
        int c2 =0;
        int c1 =0;
        for(int j=0;j<m;j++)
        {
            if(arr[j][i]==0)
            {
                c2++;
            }
           if( arr[j][i]==1)
            {
                c1++;
            }
            if(c2+c1==m && c1==1)
            {
                
             heSo[index]=c[i];
             index++;
            }
        }
    }
    for(int e=0;e<5;e++)
    {
  
    double delta[n];
    double delta1[n];
    for(int i=0;i<n;i++)
    {
        delta[i]=0;
         delta1[i]=0;
    }
    
   
   
    // delta
    double sum = 0;
    for(int i = 0 ; i < n; i++)
    {
        sum = 0;
        for(int j = 0; j < m ; j++)
        {
            sum += heSo[j] * arr[j][i];
        }
        
         delta[i] = sum - c[i];
         delta1[i]=sum-c[i];
    }

    int hesodelta=0;
    int hesomin=0;
    int k=0;
    double min[100];
    double min1[100];
 double f = 0;
     for(int i = 0 ; i < m; i++)
    {
        f += heSo[i] * b[i];
    }
    //check delta
  
for(int i=0 ;i<n-1;i++)
{
    for(int j=i+1 ;j<n;j++)
    {
        if(delta[i]<delta[j])
        {double tem = delta[i];
            delta[i]=delta[j];
            delta[j]=tem;
        }
    }
}

if( delta[0]<=0)
{
cout<<"nghiem f(x):" <<f<<endl; break;
}
else
{
    for(int i=0;i<n;i++)
    {
  if( delta1[i]==delta[0])
  {
      hesodelta=i;
  }
    }
    for(int j=0;j<m;j++)
    {
        if(arr[hesodelta][j]<=0)
        {
          k++;
        }
    }
    if(k==m)
    {
       cout<<"vo nghiem"<<endl; break;
    }
}
for(int i=0;i<m;i++)
{
    min[i]= b[i]/arr[i][hesodelta];
    min1[i]= b[i]/arr[i][hesodelta];
}
for(int i=0 ;i<m-1;i++)
{
    for(int j=i+1 ;j<m;j++)
    {
        if(min[i]>min[j])
        {
            double tem = min[i];
            min[i]=min[j];
            min[j]=tem;
        }
    }
}
for(int i=0;i<m;i++)
{
    if(min1[i]== min[0])
    {
        hesomin=i;
    }
}
// tinh lai heso
 heSo[hesomin] = c[hesodelta];
//thay b
for(int i = 0 ; i < m; i++)
        {
           if(i==hesomin)   
           {
               b[i]= b[i]/arr[hesomin][hesodelta];
           }  
           else
           {
               b[i]=b[i]- (b[hesomin]*arr[i][hesodelta])/arr[hesomin][hesodelta];
           }    
        }
        // thay arr
         double arr1[m][100];
      for(int i = 0 ; i < m; i++)
            {
                for(int j = 0; j < n ; j++)
                {
                    if(i == hesomin)
                    {
                        arr1[i][j] = (arr[i][j])/(arr[i][hesodelta]);
                    }
                    if(i!=hesomin){
                       arr1[i][j] = arr[i][j] - (arr[hesomin][j])*(arr[i][hesodelta])/(arr[hesomin][hesodelta]); 
                    }
                }
            }
     for(int i=0;i<m;i++)
     {
         for(int j=0;j<n;j++)
         {
             arr[i][j]=arr1[i][j];
         }
     }
          
   
    }

   
    
  
     
     

 

    

  


        
 
   }
