#include <cstdio>
#include <string>
#include <stdexcept>

namespace mtl{

using std::string;
using std::runtime_error;
using std::out_of_range;

template <class T>
slist<T>::slist():phead_(NULL),ptail_(NULL),size_(0){
	phead_ = ptail_ = new Node;
	ptail_->pnext = NULL;
}
template <class T>
slist<T>::~slist(){
	do{
		Node* temp = phead_;
		phead_ = phead_->pnext_;
		delete temp;
	}while(NULL != phead_);
	ptail_ = NULL;
	size_ = 0;
}
template <class T>
void slist<T>::push_back(reference v){
	Node* temp = new Node(v);
	ptail_->pnext = temp;
	ptail_ = temp;
	size_++;
}
template <class T>
void slist<T>::pop_back(){
	if(empty()){
		throw runtime_error(string("slist is null"));
	}
	Node* temp = phead_->pnext;
	while(temp->pnext != ptail_){
		temp = temp->pnext_;
	}
	delete ptail_;
	ptail_ = temp;
	ptail_->pnext_ = NULL;
}
template <class T>
void slist<T>::push_front(reference v){
	Node* temp = new Node(v);
	temp->pnext_ = phead_->pnext_;
	phead_->pnext_ = temp;
	size_++;
}
template <class T>
void slist<T>::pop_front(){
	if(empty()){
		throw runtime_error(string("slist is null"));
	}
	Node* temp = phead_->pnext_;
	phead_->pnext_ = temp->pnext_;
	delete temp;
	size_--;
}
template <class T>
typename slist<T>::reference slist<T>::front(){
	if(empty()){
		throw runtime_error(string("slist is null"));
	}
	return phead_->pnext_->data_;
}
template <class T>
typename slist<T>::const_reference slist<T>::front()const{
	return front();
}
template <class T>
typename slist<T>::reference slist<T>::back(){
	if(empty()){
		throw runtime_error(string("slist is null"));
	}
	return ptail_->data_;
}
template <class T>
typename slist<T>::const_reference slist<T>::back()const{
	return back();
}
}
