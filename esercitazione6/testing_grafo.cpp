#include <iostream>
#include <string>
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"


int main() {
    unidirected_graph<std::string> G1;


    G1.add_edge("Milano", "Torino");
    G1.add_edge("Milano", "Roma");
    G1.add_edge("Roma", "Napoli");
    G1.add_edge("Roma","Roma");

    std::cout << "Numero di nodi:: " << G1.all_nodes().size() << "\n";
    std::cout << "Numero di archi: " << G1.all_edges().size() << "\n";
    std::cout << "Le città raggiungibili da Milano direttamnete sono: \n "; 
    for(const auto&nodi : G1.neighbor("Milano")) {
	    std::cout << nodi << "\n";
	    
	    }

    // TEST numerazione in ordine cronologico
    unidirected_edge<std::string> arco_test("Milano", "Roma");
    std::cout << "\nL'arco Milano-Roma ha l'ID numero: " << G1.edge_number(arco_test) << "\n";

    // Creiamo un secondo grafo G2
    unidirected_graph<std::string> G2;
    G2.add_edge("Milano", "Roma"); 
    G2.add_edge("Napoli", "Palermo"); 

    // TESTIAMO LA SOTTRAZIONE
    std::cout << "\n TEST SOTTRAZIONE (G3 = G1 - G2) \n";
    unidirected_graph<std::string> G3 = G1 - G2;
    std::cout << "Gli archi rimasti in G3 sono:\n";
    for(const auto& arco : G3.all_edges()) {
        std::cout << "- Da " << arco.from() << " a " << arco.to() << "\n";
    }

  
    return 0;
}