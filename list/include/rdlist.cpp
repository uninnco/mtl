#include <cstdio>
#include <string>
#include <stdexcept>

namespace mtl{

using std::string;
using std::runtime_error;
using std::out_of_range;

template <class T>
rdlist<T>::rdlist():ptail_(NULL),size_(0){}
template <class T>
rdlist<T>::~rdlist(){
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
void rdlist<T>::push_back(const_reference v){
	Node* temp = new Node(v);
	if(NULL == ptail_){
		ptail_ = temp;
		ptail_->pnext_ = temp;
		ptail_->pprev_ = temp;
	}else{
		temp->pnext_ = ptail_->pnext_;
		ptail_->pnext_ = temp;
		temp->pprev_ = ptail_;
		ptail_ = temp;
		temp->pnext_->pprev_ = temp;
	}
	
	size_++;
}
template <class T>
void rdlist<T>::pop_back(){
	if(NULL == ptail_){
		throw runtime_error(string("rdlist is null"));
	}
	// TODO: 双向循环链表尾删除操作
	if(ptail_ == ptail_->pnext_){
		delete ptail_;
		ptail_	= NULL;
		return;
	}
	ptail_ ->pprev_->pnext_ = ptail_->pnext_;
	
	ptail_ = ptail_->pprev;
	delete ptail_->pnext_->pprev_;
	ptail_->pnext_->prev = ptail_->pnext_;
	size_--;
}
template <class T>
void rdlist<T>::push_front(const_reference v){
	Node* temp = new Node(v);
	// TODO: 双向循环链表头插入操作
	if(NULL == ptail_){
		ptail_ = temp;
		ptail_->pnext_ = temp;
		ptail_->pprev_ = temp;
	}else{
		temp->pnext_ = ptail_->pnext_;
		ptail_->pnext_ = temp;
		temp->pprev_ = ptail_;
		temp->pnext_->pprev_ = temp;
	size_++;
	}
}
template <class T>
void rdlist<T>::pop_front(){
	if(NULL ==ptail_){
		throw runtime_error(string("rdlist is null"));
	}
	// TODO: 双向循环链表头删除操作
	if(ptail_ == ptail_->pnext_){
		delete ptail_;
		ptail_	= NULL;
		return;
	}
	ptail_ ->pnext_ = ptail_ ->pprev_->pnext_;
	delete ptail_->pprev_;
	ptail_ ->pnext_->pprev_ = ptail_;
	size_--;
}
template <class T>
typename rdlist<T>::reference rdlist<T>::front(){
	if(NULL == ptail_){
		throw runtime_error(string("rdlist is null"));
	}
	return ptail_->pnext_->data_;
}
template <class T>
typename rdlist<T>::const_reference rdlist<T>::front()const{
	return front();
}
template <class T>
typename rdlist<T>::reference rdlist<T>::back(){
	if(NULL == ptail_){
		throw runtime_error(string("rdlist is null"));
	}
	return ptail_->data_;
}
template <class T>
typename rdlist<T>::const_reference rdlist<T>::back()const{
	return back();
}

template <class T>
typename rdlist<T>::size_type rdlist<T>::size()const{
	return size_;
}
template <class T>
bool rdlist<T>::empty()const{
	return size_ == 0;
}
template <class T>
typename rdlist<T>::reference rdlist<T>::at(typename rdlist<T>::size_type n){
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
typename rdlist<T>::reference rdlist<T>::operator[](typename rdlist<T>::size_type n){
	return at(n);
}
}
