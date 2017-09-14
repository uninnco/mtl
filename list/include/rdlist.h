#pragma once
#include <iostream>
namespace mtl{

template <class T>
class rdlist{
public:
	typedef T value_type;
	typedef long size_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* pointer;
	typedef const T* const_pointer;
	rdlist();
	~rdlist();
	inline size_type size()const;
	inline bool empty()const;
	inline void push_back(const_reference v);
	inline void pop_back();
	inline void push_front(const_reference v);
	inline void pop_front();
	inline reference front();
	inline const_reference front()const;
	inline reference back();
	inline const_reference back()const;
	inline reference at(size_type n);
	inline reference operator[](size_type n);
private:
	struct Node{
		Node(const_reference data):data_(data),pnext_(NULL){}
		value_type data_;
		Node* pnext_;
		Node* pprev_;
	};
	Node* ptail_;
	size_type size_;
};
}
#include "rdlist.cpp"
