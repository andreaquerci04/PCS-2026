#include "unidirected_graph.hpp"
#include "fifo.hpp"
#include "lifo.hpp"
#include <iostream>
#include <map>
#include <limits>
#include "queue_priority.hpp"

template <typename T, typename container>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& grafo, const T& nodo_iniziale, container& c){

	std::set<T> nodi_non_visitati = grafo.all_nodes();
	c.put(nodo_iniziale);
	unidirected_graph<T> albero_visita;
	
	while(!c.empty())
	{	
		
		std::optional<T> res = c.get();
		if (!res.has_value()) continue; 
		T u = res.value();


		nodi_non_visitati.extract(u);
		
		for(const auto& w : grafo.neighbor(u))
		{
			if (nodi_non_visitati.contains(w)) {
                nodi_non_visitati.extract(w); 
                c.put(w);
                albero_visita.add_edge(u, w);         
            }
		}
	}
	return albero_visita;}
	

	
template <typename T>	
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& grafo, const T& nodo_iniziale){
	
	unidirected_graph<T> albero_visita;
	std::set<T> nodi_non_visitati = grafo.all_nodes();
	
	DFS_visit(grafo, nodo_iniziale, albero_visita, nodi_non_visitati);
	
	return albero_visita;}
	

template <typename T>
void DFS_visit(const unidirected_graph<T>& grafo, const T& nodo, unidirected_graph<T>& albero_visita, std::set<T>& nodi_non_visitati) {
	
	nodi_non_visitati.extract(nodo);
	
	for(const auto& w : grafo.neighbor(nodo))
	{
		if(nodi_non_visitati.contains(w)) {
			albero_visita.add_edge(nodo,w);
			DFS_visit(grafo,w,albero_visita,nodi_non_visitati);
			}
		}
	
	}


template <typename T>
std::pair<std::map<T, int>, std::map<T, T>> dijkstra(const unidirected_graph<T>& grafo, const T& nodo){
	 
	std::map<T, int> dist;
  	std::map<T, T> pred;
  	queue_priority<T> coda_priorita;
	
	
	//loop su tutti i nodi per inizializzare mappa dist
	for(const auto& w : grafo.all_nodes())
	{
	dist[w] = std::numeric_limits<int>::max();
	}
	//iniziallizzo nodo iniziale
	dist[nodo] = 0;
	pred[nodo] = nodo;

	for(const auto& w : grafo.all_nodes())
	{
		coda_priorita.put(w,dist[w]);	
		
	}
	while (!coda_priorita.empty())
	{
		
	 T u = coda_priorita.get();
	 for(const auto&w : grafo.neighbor(u))
	 {
		if(dist[w] > dist[u] + 1)
		{
		  dist[w] = dist[u] +1;
		  pred[w] = u;
		  coda_priorita.put(w,dist[w]);	
		} 
		 
	 }
		
	}

    return {dist, pred};}