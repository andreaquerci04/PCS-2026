#include <iostream>
#include "rational.hpp"

int main(){
	rational<int> a(1,0);
	rational<int> b(3,-4);


	rational<int> c = a/b;
	rational<int> f = b/a;
	
	std::cout << c << "\n";
	std::cout << f << "\n";
	
	
	
	
	return 0;
	};