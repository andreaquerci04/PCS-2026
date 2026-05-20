#include <Eigen/Dense>
#include <Eigen/SVD>
#include <vector>



Eigen::VectorXd gradiente_coniugato(const Eigen::MatrixXd& A, const Eigen::VectorXd& b){
	
	auto n = A.rows();
	Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
	Eigen::VectorXd r = b - A * x;
	Eigen::VectorXd p = b - A * x;
	
	double res_norm_0 = r.norm();
	const unsigned int it_max = 10000;
	unsigned int it = 0;
	const double res_tol = 1.0e-12;
	
	while (it < it_max && r.norm() > res_tol * res_norm_0)
	{
		auto Ap = A * p; 
        auto alpha = p.dot(r) / p.dot(Ap);
        x = x + alpha * p;
        r = b - A * x;
        auto beta = p.dot(A * r) / p.dot(Ap);
        p = r - beta * p; 
		
		it++;	
	}

	return x;
	}