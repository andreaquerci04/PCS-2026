#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

double std_dev(double ar[], int dimensione, double med){
	double s = 0;
	for (int i=0; i< dimensione; i++){
		
		s +=std::pow(ar[i] - med,2);
		
		}
	double dev = std::sqrt(s/dimensione);
	return dev;
}

int main() {
	static const int N = 5;
	double arr[N] = {0, 10, -10.4, 23, 50};
	double minimo = *std::min_element(arr,arr+N);
	double massimo = *std::max_element(arr,arr+N);
	double media = std::accumulate(arr, arr + N, 0.0) / N;
	double deviazione = std_dev(arr ,N,media);


	
	std::cout <<"Minimo: "<< minimo<< "\n" << "Massimo: "<<massimo << "\n" <<"Media: " <<media<<"\n" << "Deviazione standard: "<<deviazione<<"\n";
		
}
	