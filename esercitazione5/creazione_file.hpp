#pragma once // Evita che il file venga incluso due volte per sbaglio nello stesso file
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// Usiamo due tipi generici T e U, così puoi passare int, double, float, ecc.

void salva_risultati(const std::string& nome_file, const std::vector<int>& dimensione, const std::vector<double>& tempi) {
    std::ofstream mioFile(nome_file);

    if (mioFile.is_open()) {
        mioFile << "Taglia_N;Tempo_Esecuzione\n";

        
        int min_size = std::min(dimensione.size(), tempi.size());

        for (int i = 0; i < min_size; ++i) {
            mioFile << dimensione[i] << ";" << tempi[i] << "\n";
        }

        mioFile.close();
            } else {
        std::cerr << "Errore: impossibile creare il file '" << nome_file << "'\n";
    }
}