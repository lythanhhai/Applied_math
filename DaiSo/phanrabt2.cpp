#include "Eigen/Eigenvalues" 
#include "Eigen/Core"// tệp tiêu đề 
#include <iostream> 
#include <complex>
using namespace std;


  int main () { 
  int n =0,m=0;
  cout<< "nhap n=";
  cin>>n;
  cout<< "nhap m=";
  cin>>m;
  
	
Eigen::MatrixXd A(n,m);

for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "nhap a[" << i << "][" << j << "]: ";
			cin >> A(i,j);
		}
  }
  cout << "matrix A:" << endl << A << endl;
  

Eigen::JacobiSVD<Eigen::MatrixXd> svd(A,Eigen:: ComputeFullU  | Eigen::ComputeFullV );

cout << "D :" << endl << svd.singularValues() << endl;
cout << " U matrix:" << endl <<svd.matrixU()<< endl;
cout << " V matrix:" << endl <<svd.matrixV()<< endl;

return 0;
  }
