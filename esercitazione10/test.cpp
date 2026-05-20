#include "gradiente_coniugato.hpp"
#include <iostream>

int main(){
	const double tol = 1.0e-15;
	unsigned int n = 15;
	Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);


  Eigen::MatrixXd A = B.transpose() * B;
  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);

  Eigen::VectorXd b = A * x_ex;
  
  Eigen::VectorXd x = gradiente_coniugato(A,b);
	
	std::cout << x << "\n";

	return 0;}