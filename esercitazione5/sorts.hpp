#include <algorithm>
#include <vector>
#include <limits>
#include <type_traits>
#include <string>

/* BUBBLE SORT */
template <typename T>
void bubble_sort(std::vector<T>& vec) {
	if (vec.size()<2 ) return;
		
	for (int i=0; i< vec.size()-1 ; i++ ) {
		for (int j=vec.size()-1 ; j > i; j--) {
			if (vec[j]<vec[j-1]) {
				std::swap(vec[j],vec[j-1]);
				}	
			}	
		}
	return;
	}
	



/* INSERCTION SORT */
template <typename T>
void inserction_sort(std::vector<T>& vec) {
	if (vec.size()<2 ) return;
	
		for (int j=1; j< vec.size() ; j++ ) {
			T key =vec[j];
			int i = j-1;
			 while (i >=0 and vec[i]>key) {
				 vec[i+1] = vec[i];
				 i = i-1;
				 
				 }
			vec[i+1] = key;
		
		}
	return;
	}
	




/* SELECTION SORT */
template <typename T>
void selection_sort(std::vector<T>& vec) {
	if (vec.size()<2 ) return;
	
	for (int i=0; i< vec.size()-1 ; i++ ) {
		int min_index = i;
		for (int j=i+1 ; j < vec.size(); j++) {
			if (vec[j]<vec[min_index]) {
				min_index = j;}	
			}
			
		std::swap(vec[i],vec[min_index]);	
		}
	return;
	}	




/* MERGE*/
template <typename T>
void merge(std::vector<T>& vec, int p, int q, int r){
	int n1 = q-p+1;
	int n2 = r-q;
	
	std::vector<T> L(n1+1);
	std::vector<T> R(n2+1);
	
	for(int i = 0; i < n1; i++){
		L[i] = vec[p+i];
		}
	
	for(int j = 0; j <n2; j++){
		R[j] = vec[q+1+j];	
		}
	if constexpr (std::is_same_v<T, std::string>) {
		L[n1] = "~~~~~";
		R[n2] = "~~~~~";
		
		}
	else {
	L[n1] = std::numeric_limits<T>::max();
    R[n2] = std::numeric_limits<T>::max();
    }
    int i = 0;
    int j = 0;
    
    for(int k = p; k <= r; k++){
	    if (L[i] <= R[j]) {
		    vec[k] = L[i];
		    i +=1;}
		    
	    else {
		    vec[k] = R[j];
		    j +=1;}   
	    }
	return;
	}
/* MERGE SORT*/
template <typename T>
void merge_sort(std::vector<T>& vec, int p, int r) {
	if (p < r) {
		int q = (p+r)/2;
		merge_sort(vec,p,q);
		merge_sort(vec,q+1,r);
		merge(vec,p,q,r);
		}	
	return;	
	}	
	
	

/*PARTITION */
template <typename T>
int partition(std::vector<T>& vec, int p, int r){
	T x = vec[r];
	int i = p-1;
	
	for (int j = p; j < r; j++) {
		if (vec[j] <= x) {
			i += 1;
			std::swap(vec[i],vec[j]);
			
			}
		} 
	
	std::swap(vec[i+1],vec[r]);
	return i+1;
	}	
/*QUICKSORT */
template <typename T>
void quick_sort(std::vector<T>& vec, int p, int r) {
	if (p<r) {
		int q = partition(vec,p,r);
		quick_sort(vec,p,q-1);
		quick_sort(vec,q+1,r);
		}
	return;
	}

// SORTING MISTO (INSERCTION-QUICK)
template <typename T>
void mix_sort(std::vector<T>& vec, int p, int r) {
	if (vec.size()<50) {
		inserction_sort(vec);
		}
	else {quick_sort(vec,p,r);}	
	return;
	}


/* CONTROLLO SORTING */
template <typename T>
bool is_sorted(const std::vector<T>& vec) {
	if (vec.size() < 2) {return true;}
	else { 
	for (int i =1; i< vec.size(); i++) {
		if (vec[i]<vec[i-1]) { return false;}
		
		}
	
	return true;}
	}