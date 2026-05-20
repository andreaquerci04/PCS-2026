#include <list>
#include <optional>

template <typename T>
class fifo{
	private:
	std::list<T> l;
	public:
	fifo() {}
	bool empty() const{return l.empty();}
	
	std::optional<T> get(){
		if (empty()){return std::nullopt;}
		 T a = l.front();
		l.pop_front();
		return a;}
		
	fifo& put(const T& a) {
		l.push_back(a);
		return *this;} 
};