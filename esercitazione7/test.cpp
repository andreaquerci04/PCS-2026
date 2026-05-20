#include <iostream>
#include "visit.hpp"
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"

int main() {
    unidirected_graph<int> G1;
    G1.add_edge(1,3);
    G1.add_edge(1,2);
    G1.add_edge(1,4);
    G1.add_edge(1,6);
    G1.add_edge(3,6);
    G1.add_edge(6,8);
    G1.add_edge(2,4);
    G1.add_edge(2,5);
    G1.add_edge(2,7);
    G1.add_edge(4,6);
    G1.add_edge(4,7);
    G1.add_edge(5,7);
    G1.add_edge(7,9);
    G1.add_edge(9,8);
    G1.add_edge(6,8);
    G1.add_edge(7,6);    


    // Esporta il file
	lifo<int> stack;
	fifo<int> coda;
	unidirected_graph<int> grafo_dfs = graph_visit(G1,1,stack); 
	unidirected_graph<int> grafo_bfs= graph_visit(G1,1,coda); 
	unidirected_graph<int> grafo_dfs_recursive = recursive_dfs(G1,1);  
	
	
	grafo_dfs_recursive.write_to_dot("dfs_recursive.dot");
	grafo_dfs.write_to_dot("dfs.dot");
	grafo_bfs.write_to_dot("bfs.dot");
	G1.write_to_dot("grafico_inziale.dot");
	
    auto [dist, pred] = dijkstra(G1, 1);

    // stampa le distanze
    std::cout << "DISTANZE" << std::endl;
    for (const auto& [nodo, distanza] : dist) {
        if (distanza == std::numeric_limits<int>::max())
            std::cout << "1 -> " << nodo << " : non raggiungibile" << std::endl;
        else
            std::cout << "1 -> " << nodo << " : " << distanza << std::endl;
    }

    // stampa i predecessori
    std::cout << "\nPREDECESSORI" << std::endl;
    for (const auto& [nodo, predecessore] : pred) {
        std::cout << "pred[" << nodo << "] = " << predecessore << std::endl;
    }
	
    return 0;
    
    
    
    
}