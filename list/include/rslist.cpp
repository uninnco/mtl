#include <cstdio>
#include <string>
#include <stdexcept>

namespace mtl{

using std::string;
using std::runtime_error;
using std::out_of_range;

template <class T>
rslist<T>::rslist():ptail_(NULL),size_(0){}
template <class T>
rslist<T>::~rslist(){
	if(NULL != ptail_){
#ifdef METHOD
		Node* temp = ptail_->pnext_;
		ptail_->pnext_ = NULL;
		ptail_ = temp;
		do{
			Node* temp = ptail_;
			ptail_ = ptail_->pnext_;
			delete temp;
		}while(NULL != ptail_);
#else
		Node* temp = ptail_;
		do{
			Node* p = temp;
			temp = temp->pnext_;
			delete p;
		}while(temp != ptail_);
#endif
	}
	size_ = 0;

}
template <class T>
void rslist<T>::push_back(const_reference v){
	Node* temp = new Node(v);
	if(NULL == ptail_){
		ptail_ = temp;
		ptail_->pnext_ = temp;
	}else{
		temp->pnext_ = ptail_->pnext_;
		ptail_->pnext_ = temp;
		ptail_ = temp;
	}
	size_++;
}
template <class T>
void rslist<T>::pop_back(){
	if(NULL == ptail_){
		throw runtime_error(string("rslist is null"));
	}
	// TODO: 单向循环链表尾删除操作
	if(ptail_ == ptail_->pnext_){
		delete ptail_;
		ptail_ = NULL;
		return;
	}
	Node* temp =ptail_;
	while(temp->pnext_ != ptail_)	temp = temp->pnext_;
	temp->pnext_ = ptail_->pnext_;
	delete ptail_;
	size_--;
}
template <class T>
void rslist<T>::push_front(const_reference v){
	Node* temp = new Node(v);
	if(NULL == ptail_){
		ptail_ = temp;
		ptail_->pnext_ = temp;
	}else{
		temp->pnext_ = ptail_->pnext_;
		ptail_->pnext_ = temp;
	}
	size_++;
}
template <class T>
void rslist<T>::pop_front(){
	if(NULL == ptail_){
		throw runtime_error(string("rslist is null"));
	}
	// TODO: 单向循环链表头删除操作
	if(ptail_ == ptail_->pnext_){
		delete ptail_;
		ptail_ = NULL;
		return;
	}
	Node* temp =ptail_->pnext_->pnext_;
	delete ptail_->pnext_;
	ptail_->pnext_ = temp;
	size_--;
}
template <class T>
typename rslist<T>::reference rslist<T>::front(){
	if(NULL == ptail_){
		throw runtime_error(string("rslist is null"));
	}
	return ptail_->pnext_->data_;
}
template <class T>
typename rslist<T>::const_reference rslist<T>::front()const{
	return front();
}
template <class T>
typename rslist<T>::reference rslist<T>::back(){
	if(NULL == ptail_){
		throw runtime_error(string("rslist is null"));
	}
	return ptail_->data_;
}
template <class T>
typename rslist<T>::const_reference rslist<T>::back()const{
	return back();
}

template <class T>
typename rslist<T>::size_type rslist<T>::size()const{
	return size_;
}
template <class T>
bool rslist<T>::empty()const{
	return size_ == 0;
}
template <class T>
typename rslist<T>::reference rslist<T>::at(typename rslist<T>::size_type n){
	if(size_ <= n){
		throw out_of_range(string("n over size"));
	}
	Node* temp = ptail_->pnext_;
	size_type i = 0;
	while(i++ != n){
		temp = temp->pnext_;
	}
	return temp->data_;
}
template <class T>
typename rslist<T>::reference rslist<T>::operator[](typename rslist<T>::size_type n){
	return at(n);
}
}
