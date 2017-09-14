#include <deque>
#include <list>
#include <iostream>

using std::deque;
using std::list;
using std::cout;
using std::endl;

namespace mtl{
template <class T,class C = deque<T> >
class queue{
public:
	queue(){}
	queue(C const& c):container_(c){}
	bool empty()const{
		return container_.empty();
	}
	typename C::size_type size()const{
		return container_.size();
	}
	typename C::reference back(){
		return container_.back();
	}
	typename C::reference front(){
		return container_.front();
	}
	void push(typename C::value_type v){
		container_.push_back(v);
	}
	void pop(){
		container_.pop_back();
	}
private:
	C container_;
};
}
int main(){
	int arr[] = {1,2,3,4,5,6};
	list<int > vec(arr,arr+6);
	mtl::queue<int,list<int> > s(vec);
	while(!s.empty()){
		cout << s.back() << endl;
		s.pop();
	}
}
