#include "../Eigen/Core"
#include "../Eigen/Eigenvalues"
#include <math.h>
#include <iostream>
#include <complex>
using namespace std;
using namespace Eigen;

void ketQua(Eigen::MatrixXd matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "nhap a[" << i << "][" << j << "]: ";
			cin >> matrix(i,j);
		}
	}
	cout << "matrix goc: " << endl << matrix << endl;
	Eigen::JacobiSVD<Eigen::MatrixXd> svd(matrix, Eigen::ComputeFullU | Eigen::ComputeFullV);

	cout << "D: " << endl << svd.singularValues() << endl;
	cout << "U matrix: " << endl << svd.matrixU() << endl;
	cout << "V matrix: " << endl << svd.matrixV() << endl;
}


int main()
{
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int m;
	printf("Nhap m = ");
	scanf("%d", &m);
	Eigen::MatrixXd M1(n,m);
	ketQua(M1, n, m);
	
}
