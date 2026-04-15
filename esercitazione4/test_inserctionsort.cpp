#include "sorts.hpp"
#include <iostream>
#include <vector>
#include "randfiller.h"
#include "timecounter.h"
#include <chrono>
#include <fstream>


template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n" << "\n";
}

int main() {
	std::ofstream mio_file("risultati_inserction.txt");
	mio_file << "DimensioneVettore Tempo" << std::endl;
	randfiller rf;
	timecounter timer;
	
	int status = 0;
	std::vector<int> lunghezze;
	lunghezze.resize(100);
	rf.fill(lunghezze,0,100);
	
	
	std::vector<std::string> stringhe = {"mela", "banana", "arancia","ciao","prova","roma","milano"};
	inserction_sort(stringhe);
	if (not is_sorted(stringhe)) {
			status = 1;
			}
		
		
	for (int i =0; i <lunghezze.size(); i++) {
		randfiller r;
		std::vector<int> vi;
		vi.resize(lunghezze[i]);
		r.fill(vi,-50,50);
		
		timer.tic();
		inserction_sort(vi);
		double tempo_impiegato = timer.toc();
		mio_file << lunghezze[i] << " " << tempo_impiegato << "\n";
		
		if (not is_sorted(vi)) {
			status = 1;
			}
		}
		
	mio_file.close();
	return status;
	
	}
