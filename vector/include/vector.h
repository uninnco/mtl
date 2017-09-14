#pragma once 
#include <cstdlib>

namespace mtl{
template <class T>
class vector{
public:
	vector();
	vector(vector const& v);
	~vector();
	vector& operator=(vector const& v);
	inline size_t size();
	inline size_t capacity();
	inline void resize(size_t n,T* c = NULL);
	inline bool empty();
	inline void reserve(size_t n);
	inline void clear();
	inline T& front();
	inline T const& front()const;
	inline T& back();
	inline T const& back()const;
	inline T& at(size_t n);
	inline T const& at(size_t n)const;
	inline T& operator[](size_t n);
	inline T const& operator[](size_t n)const;
	inline void assign(size_t n,T const& v);
	inline void assign(size_t n,vector const& v);
	inline void push_back(T const& v);
	inline void pop_back();
	inline void insert(size_t pos,T const& v);
	inline void erase(size_t pos);
	inline void swap(vector& v);
	
private:
	T* data_;
	size_t size_;
	size_t capacity_;
};
template<class T>
void swap(vector<T>& l,vector<T>& r); 
}
#include "vector.cpp"
