#include "sorts.hpp"
#include <iostream>
#include <vector>
#include "randfiller.h"
#include "timecounter.h"
#include <chrono>
#include <fstream>
#include "creazione_file.hpp"

	
int main() {

	randfiller rf;
	timecounter timer;
	int status = 0;
//vettore che mi salva le dimensione
	std::vector<int> grandezze(100);
	for (int i = 0; i < 100; ++i) {
        grandezze[i] = i+1;
    }
	
// creo un vector dove salverò i tempi di ordinamento
	std::vector<double> tempi(100);
	
// creo i vettori da ordinare
	int righe = 100;
	int colonne;
	for (int i =1; i<righe; i++) {
		colonne = i;
		std::vector<std::vector<int>> matrice(righe, std::vector<int>(colonne, 0));
		for (int j =0; j<100; j++){
			rf.fill(matrice[j],-50,50);
			}
	
	// da questo momento inzio il ciclo di sorting
		timer.tic();
		for (int k =0;k<righe;k++) {
			inserction_sort(matrice[k]);
			}
			
		tempi[i] = timer.toc()/100.00;
	//faccio un'altro ciclo per controllare che il sorting sia stato fatto correttamente (lo faccio ora per non sballare i tempo del sorting
		for (int k=0;k<righe;k++) {
			if (not is_sorted(matrice[k])){
				status = 1;				} 
			}

			
	
		}
	
	
	salva_risultati("inserction.csv",grandezze,tempi);
	return status;
	
	}
