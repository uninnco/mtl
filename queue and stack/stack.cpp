#include <deque>
#include <vector>
#include <iostream>

using std::deque;
using std::vector;
using std::cout;
using std::endl;

namespace mtl{
template <class T,class C = deque<T> >
class stack{
public:
	stack(){}
	stack(C const& c):container_(c){}
	bool empty()const{
		return container_.empty();
	}
	typename C::size_type size()const{
		return container_.size();
	}
	typename C::reference top(){
		return container_.back();
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
	vector<int > vec(arr,arr+6);
	mtl::stack<int,vector<int> > s(vec);
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
}
