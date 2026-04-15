#include <iostream>
#include <vector>
#include "randfiller.h"
#include "timecounter.h"
#include <chrono>
#include <fstream>



int main() {
	std::ofstream mio_file("risultati_nativo.txt");
	mio_file << "DimensioneVettore Tempo" << std::endl;
	randfiller rf;
	timecounter timer;
	
	std::vector<int> lunghezze;
	lunghezze.resize(100);
	rf.fill(lunghezze,0,100);
	

	for (int i =0; i <lunghezze.size(); i++) {
		randfiller r;
		std::vector<int> vi;
		vi.resize(lunghezze[i]);
		r.fill(vi,-50,50);
		
		timer.tic();
		std::sort(vi.begin(), vi.end());
		double tempo_impiegato = timer.toc();
		mio_file << lunghezze[i] << " " << tempo_impiegato << "\n";
		}

	mio_file.close();
	return 0;
	
	}
