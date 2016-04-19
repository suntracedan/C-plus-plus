#pragma once
#include<iostream>
using namespace std;
struct A
{
public:
	int _b;
	int _a;
};
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{
	}
	~AutoPtr()
	{
		if(_ptr!=NULL)
			delete _ptr;
		cout<<"~AutoPtr"<<endl;
	}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr=NULL;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if(this!=&ap)
		{
			delete _str;
			_str=ap._ptr;
			ap._ptr=NULL;
		}
		return  *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T *operator->()
	{
		return _ptr;
	}
protected:
	T* _ptr;
};
template<typename T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr)
		:_ptr(ptr)
	{
	}
	~ScopedPtr()
	{
		if(_ptr!=NULL)
			delete _ptr;
	}
protected:
	ScopedPtr(ScopedPtr<T>& ptr);
	ScopedPtr<T>& operator=(ScopedPtr<T>& ptr);
public:
	T& operator*()
	{
		return *_ptr;
	}
	T *operator->()
	{
		return _ptr;
	}
protected:
	T* _ptr;
};


template<typename T>
class ScopedArr
{
public:
	ScopedArr(T* ptr)
		:_ptr(ptr)
	{
	}
	~ScopedArr()
	{
		if(_ptr!=NULL)
			delete[] _ptr;
	}
protected:
	ScopedArr(ScopedPtr<T>& ptr);
	ScopedArr<T>& operator=(ScopedArr<T>& ptr);
public:
	T& operator*()
	{
		return *_ptr;
	}
	T *operator->()
	{
		return _ptr;
	}
	T& operator[](size_t index)
	{
		return _ptr[index];
	}
protected:
	T* _ptr;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		,_pcount(new long(1))
	{
		cout<<"构造函数"<<endl;
	}
	~SharedPtr()
	{
		Release();
	}
	SharedPtr(const SharedPtr<T>& ptr)
		:_ptr(ptr._ptr)
		,_pcount(ptr._pcount)
	{
		++(*_pcount);
		cout<<"拷贝构造"<<endl;
	}
	SharedPtr<T>& operator=(SharedPtr<T>& ptr)
	{
		//if(_ptr!=ptr._ptr)
		//{
		//	Release();
		//	_ptr=ptr._ptr;
		//	_pcount=ptr._pcount;
		//	++*_pcount;
		//}
		swap(_ptr,ptr._ptr);
		swap(_pcount,ptr._pcount);
		return *this;
	}
	public:
	T& operator*()
	{
		return *_ptr;
	}
	T *operator->()
	{
		return _ptr;
	}
	long Usecount()
	{
		return *_pcount;
	}
protected:
	T* _ptr;
	long* _pcount;
protected:
	void Release()
	{
		if(--*_pcount==0)
		{
			delete _pcount;
			delete _ptr;
		}
	}
};


template<typename T>
class SharedArr
{
public:
	SharedArr(T* ptr)
		:_ptr(ptr)
		,_pcount(new long(1))
	{
	}
	~SharedArr()
	{
		Release();
	}
	SharedArr(const SharedArr<T>& arr)
		:_ptr(arr._ptr)
		,_pcount(arr._pcount)
	{
		++(*_pcount);
	}
	SharedArr<T>& operator=(const SharedArr<T>& arr)
	{
		if(_ptr!=arr._ptr)
		{
			Release();
			_ptr=arr._ptr;
			_pcount=arr._pcount;
			++(*_pcount);
		}
		return *this;
	}
	public:
	T& operator*()
	{
		return *_ptr;
	}
	T *operator->()
	{
		return _ptr;
	}
	long Usecount()
	{
		return *_pcount;
	}
	T* GetPtr()
	{
		return _ptr;
	}
	T& operator[](size_t index)
	{
		return _ptr[index];
	}
protected:
	T* _ptr;
	long* _pcount;
protected:
	void Release()
	{
		if(--*_pcount==0)
		{
			delete[] _pcount;
			delete _ptr;
		}
	}
};