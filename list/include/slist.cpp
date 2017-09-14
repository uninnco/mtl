#include <cstdio>
#include <string>
#include <stdexcept>

namespace mtl{
using std::string;
using std::runtime_error;
using std::out_of_range;

template <class T>
slist<T>::slist():phead_(NULL),ptail_(NULL),size_(0){}
template <class T>
slist<T>::~slist(){
	if(NULL!= phead_){
		do{
			Node* temp = phead_;
			phead_ = phead_-> pnext_;
			delete temp;
		}while(NULL != phead_);
		ptail_ = NULL;	
		size_ = 0;
	}
}
template <class T>
void slist<T>::push_back(reference v){
	pointer temp = new value_type(v);
	if(NULL == phead_){
		phead_ = temp;
	}else{
		ptail_ -> pnext_ = temp;
	}
	ptail_ = temp;
	size_++;
}
template <class T>
void slist<T>::pop_back(){
	if(NULL == phead_){
		throw runtime_error(string("slist is NULL"));
	}
	if(phead_ == ptail_){
		delete phead_;
		phead_= ptail_ = NULL;
		return;
	}
	pointer temp = phead_;
	while(temp -> pnext_ != ptail_){
		temp = temp->pnext_;
	}
	delete ptail_;
	ptail_ = temp;
	ptail_->pnext_ = NULL;
}
template <class T>
void slist<T>::push_front(reference v){
	pointer temp = new value_type(v);
	temp->pnext_ = phead_;
	phead_ = temp;
	if(NULL  == ptail_){
		ptail = phead_;
	}
	size_++;
}
template <class T>
void slist<T>::pop_front(){
	if(NULL == phead_){
		throw runtime_error(string("slist is NULL"));
	}
	pointer temp = phead_;
	phead_ = phead_-> pnext_;
	delete temp;
	if(NULL == phead_){
		ptail_ = NULL;
	}
	size_--;
}
template <class T>
typename slist<T>::reference slist<T>::front(){
	if(NULL == phead_){
		throw runtime_error(string("slist is NULL"));
	}
	return phead_->data_;
}
template <class T> 
typename slist<T>::const_reference slist<T>::front()const{
	return front();
}
template <class T>
typename slist<T>::reference slist<T>::back(){
	if(NULL == phead_){
		throw runtime_error(string("slist is NULL"));
	}
	return ptail_->data_;
}
template <class T>
typename slist<T>::const_reference slist<T>::back()const{
	return back();
}
}
