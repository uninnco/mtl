#pragma once

namespace mtl{
class slist{
public:
	typedef T value_type;
	typedef long size_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef T* pointer;
	typedef const T* const_pointer;
	slist();
	~slist();
	inline size_type size()const;
	inline void push_back(reference v);
	inline void pop_back();
	inline void push_front(reference v);
	inline void pop_frontZ();
	inline reference front();
	inline const_reference front()const;
	inline reference back();
	inline const_reference back()const;
	inline reference at(size_type n);
private:
	struct Node{
		value_type data_;
		pointer pnext;
	};
	Node* phead_;
	Node* ptail_;
	size_type size_;
};
}
#include "slist.cpp"
