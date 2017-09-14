#include <cstdio>
#include <string>
#include <stdexcept>

namespace mtl{

using std::string;
using std::runtime_error;
using std::out_of_range;

template <class T>
rlist<T>::rlist():phead_(NULL),ptail_(NULL),size_(0){}

template <class T>
rlist<T>::~rlist(){
	if(NULL != phead_){
		do{
			Node* temp = phead_;
			phead_ = phead_->pnext_;
			delete temp;
		}while(NULL != phead_);
		ptail_ = NULL;
		size_ = 0;
	}
}
template <class T>
void rlist<T>::push_back(reference v){
	Node* temp = new Node(v);
	if(NULL == phead_){
		phead_=temp;
	}else{
		temp->pprev_ = ptail_;
		ptail_->pnext = temp;
	}
	ptail_ = temp;
	size_++;
}
template <class T>
void rlist<T>::pop_back(){
	if(NULL == phead_){
		throw runtime_error(string("rlist is null"));
	}
	if(phead_ == ptail_){
		delete phead_;
		phead_= ptail_ = NULL;
	}else{
		ptail_ = ptail_->pprev_;
		delete ptail_->pnext_;
		ptail_->pnext_ = NULL;
	}
}
template <class T>
void rlist<T>::push_front(reference v){
	Node* temp = new Node(v);
	temp->pnext_ = phead_;
	phead->pprev_ = temp;
	phead_ = temp;
	if(NULL == ptail_){
		ptail_ = phead_;
	}
	size_++;
}
template <class T>
void rlist<T>::pop_front(){
	if(NULL == phead_){
		throw runtime_error(string("rlist is null"));
	}
	if(phead_ == ptail_){
		delete phead_;
		ptail_ = phead_ = NULL;
	}else{
		phead_ = phead_->pnext_;
		delete phead_->pprev_;
		phead_->pprev_ = NULL;
	}
	size_--;
}
template <class T>
typename rlist<T>::reference rlist<T>::front(){
	if(NULL == phead_){
		throw runtime_error(string("rlist is null"));
	}
	return phead_->data_;
}
template <class T>
typename rlist<T>::const_reference rlist<T>::front()const{
	return front();
}
template <class T>
typename rlist<T>::reference rlist<T>::back(){
	if(NULL == phead_){
		throw runtime_error(string("rlist is null"));
	}
	return ptail_->data_;
}
template <class T>
typename rlist<T>::const_reference rlist<T>::back()const{
	return back();
}
}
