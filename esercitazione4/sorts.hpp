#include <algorithm>
#include <vector>



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