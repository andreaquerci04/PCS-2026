#include <list>
#include <optional>

template <typename T>
class lifo{
	private:
	std::list<T> l;
	public:
	lifo() {}
	bool empty() const{return l.empty();}
	
	std::optional<T> get(){ 
		if (empty()){return std::nullopt;}
		T a = l.back();
		l.pop_back();
		return a;}
		
	lifo& put(const T& a) {
		l.push_back(a);
		return *this;} 
};