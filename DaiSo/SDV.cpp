#include "../Eigen/Eigenvalues" 
#include <iostream> 
#include<complex>
using namespace std;

int main () { 
  int n =0,m=0;
  cout << "nhap n=";
  cin >> n;
  cout << "nhap m=";
  cin >> m;
  
	
  Eigen::MatrixXd A(n,m);
  Eigen::MatrixXd B(m,n);
  Eigen::MatrixXd E(n,n);
  Eigen::MatrixXd D(m,m);

  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cout << "nhap a[" << i << "][" << j << "]: ";
        cin >> A(i,j);
      }
    }
    cout << "matrix A:" << endl << A << endl;
 
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      B(j,i) = A(i,j);
    }
  }

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
     E(i,j)=0;
     for(int l = 0; l < m; l++)
     {
       E(i,j) += B(l,j) * A(i,l);
     }
     cout<<E(i,j)<<endl;
    }
  }

  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < m; j++)
    {
      D(i,j)=0;
      for(int l = 0; l < n; l++)
      {
          D(i,j) += B(i,l) * A(l,j);
      }
    }
  }

  Eigen::EigenSolver < Eigen::MatrixXd> s (E); 
  Eigen::EigenSolver < Eigen::MatrixXd> t (D);
  cout<<"B:"<<endl;
  cout<<B<<endl; 
  
   

  cout<< s.eigenvalues() <<endl;
  
  cout << "U:"<< endl;
  cout << (s.eigenvectors()) << endl;
  cout << "V:" << endl;
  cout<< (t.eigenvectors());
  }