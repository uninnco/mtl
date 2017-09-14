#include <stdexcept>
#include <string>
namespace mtl
{

using std::runtime_error;
using std::string;
using std::out_of_range;

template<class T> vector<T>::vector():data_(NULL),size_(0),capacity_(0){}
template<class T> vector<T>::vector(vector const& v):data_(v.data_),size_(v.size_),capacity_(capacity_){
	delete [] data_;
	data_ = NULL;
	if(NULL != v.data_){
		data_= new T[v.capacity_];
		for(size_t i = 0; i < size_; i++){
			data_[i] = v.data_[i];
		}
	}
}
template <class T> vector<T>::~vector(){
	clear();
}
template <class T> vector<T>& vector<T>::operator=(vector<T> const& v){
	delete [] data_;
	data_ = NULL;
	if(NULL != v.data_){
		data_ = new T[v.capacity_];
		for(size_t i = 0; i < size_ ; i++){
			data_[i] = v.data_[i];
		}
	}
}
template <class T> /*inline */size_t vector<T>::size(){return size_;} 
template <class T> /*inline */size_t vector<T>::capacity(){return capacity_;}
template <class T> inline void  vector<T>::resize(size_t n,T* c  ){

	capacity_ = size_ = n;
	if(n > capacity_){
		T* temp = data_;
		data_ = new T[capacity_];
		for(size_t i = 0; i < size_; i++){
			data_[i] = temp[i];
		}	
		delete [] temp;
	}
	if(n > size_){
		for(size_t i = n; i < size_; i++){
			data_[i] = c;
			
		}
	}
}
template<class T> /*inline*/bool vector<T>::empty(){
	return size_ == 0;
}
template<class T> /*inline*/void vector<T>::reserve(size_t n){
	if(n < capacity_){
		return;
	}
	capacity_ = n;
	T* temp = data_;
	data_ = new T[capacity_];
	for(size_t i = 0; i < size_; i++){
		data_[i] = temp[i];
	}
	delete [] temp;
}
template<class T>/*inline*/T& vector<T>::at(size_t n){
	if(NULL == data_){
		throw runtime_error(string("vector is NULL"));
	}
	if(size_ <= n){
		throw out_of_range(string("n over size"));
	}
	return data_[n];
}
template<class T>/*inline*/ const T& vector<T>::at(size_t n)const{return at(n);}
template<class T>/*inline*/ T& vector<T>::operator[](size_t n){
	return at(n);
}
template<class T>/*inline*/ T const& vector<T>::operator[](size_t n)const{
	return at(n);
}
template<class T>/*inline*/T& vector<T>::front(){
	return at[0];
}
template<class T>/*inline*/T const& vector<T>::front()const{
	return at[0];	
}
template<class T>/*inline*/T& vector<T>::back(){
	return at[size_-1];
}
template<class T>/*inline*/T const& vector<T>::back()const{
	return at[size_-1];
}
template<class T>/*inline*/void vector<T>::clear(){
	if(NULL != data_){
		delete [] data_;
		data_ = NULL;
		size_ = capacity_=0;
	}
}
template<class T>/*inline*/void vector<T>::assign(size_t n,T const& v){
	clear();
	capacity_ = size_ = n;
	data_ = new T[capacity_];
	for(size_t i = 0; i < size_; i++){
		data_[i] = v;
	}
}	
template<class T>/*inline*/void vector<T>::assign(size_t n,vector<T> const& v){
	clear();
	capacity_ = size_ = n;
	data_ = new T[capacity_];
	for(size_t i = 0; i < size_; i++){
		data_[i] = v.data_[i];
	}
}	
template<class T>/*inline*/void vector<T>::push_back(T const& v){
	if(NULL == data_){
		size_ = capacity_= 1;
		data_ = new T[1];
		data_[0] = v;
		return ;
	}
	if(size_ >= capacity_){
		reserve(capacity_ << 1);
	}
	size_++;
	data_[size_ - 1] = v;
}
template<class T>/*inline*/void vector<T>::pop_back(){
	if(NULL == data_){
		throw runtime_error(string("vector is NULL"));
	}
	size_--;
}
template<class T>/*inline*/void vector<T>::insert(size_t pos,T const& v){
	if(NULL == data_&& 0 == pos||size_ == pos){
		push_back(v);
		return;
	}
	if(NULL == data_){
		throw runtime_error(string("vector is NULL"));
	}
	if(size_ <= pos){
		reserve(capacity_ << 1);
	}
	for(size_t i = size_ ; i >= pos; i--){
		data_[i] = data_[i-1];
	}
	data_[pos] = v;
	size_++;
}
template<class T>/*inline*/void vector<T>::erase(size_t pos){
	if(NULL == data_){
		throw runtime_error(string("vector is NULL"));
	}
	if(size_ <= pos){
		throw out_of_range(string("n over size"));
	}
	for(size_t i = pos; i < size_ -1;i++){
		data_[i] = data_[i+1];	
	}
	size_--;
}
template<class T>/*inline*/void vector<T>::swap(vector& v){
	if(NULL == data_&& NULL==v.data_){
		return;
	}
	T* temp = new T[capacity_];
	temp = data_;
	data_ = new T[v.capacity_];
	data_ = v.data_;
	v = new T[capacity_];
	v.data_ = temp;
	capacity_ = capacity_^(v.capacity_);
	v.capacity_ = (v.capacity_)^capacity_;
	capacity_ = capacity_^(v.capacity_);
}
template<class T>void swap(vector<T>& l,vector<T>& r){
	l.swap(r);
}
}
