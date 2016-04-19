#pragma once
#include<iostream>
#include<memory>
#define _CRT_SECURE_NO_WARNING
using namespace std;

struct A
{
	int _a;
};
template<typename T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
		,_owner(true)
	{
	}
	~AutoPtr()
	{
		if(_owner)
		{
			delete _ptr;
		}
	}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		_owner=true;
		ap._owner=false;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if(_ptr!=ap._ptr)
		{
			delete _ptr;
			_ptr=ap._ptr;
			_owner=ap._owner;
			ap._owner=false;
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
protected:
	T* _ptr;
	bool _owner;
};


//循环引用

struct Node
{
	//shared_ptr<Node> _next;
	//shared_ptr<Node> _prev;
	weak_ptr<Node> _next;
	weak_ptr<Node> _prev;
};
void TestSharedPtr()
{
	shared_ptr<Node> cur(new Node());
    shared_ptr<Node> next(new Node());
    cur->_next=next;
	next->_prev=cur;
}

//定制删除
template<typename T,typename D>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		,_pcount(new long(1))
	{
		cout<<"构造函数"<<endl;
	}
	SharedPtr(T* ptr,D del)
		:_ptr(ptr)
		,_pcount(new long(1))
		,_del(del)
	{
	}
	~SharedPtr()
	{
		Release();
	}
	SharedPtr(SharedPtr<T,D>& ptr)
		:_ptr(ptr._ptr)
		,_pcount(ptr._pcount)
		
	{
		++(*_pcount);
		cout<<"拷贝构造"<<endl;
	}
	//SharedPtr<T,D>& operator=(SharedPtr<T,D>& ptr)
	//{
	//	//if(_ptr!=ptr._ptr)
	//	//{
	//	//	Release();
	//	//	_ptr=ptr._ptr;
	//	//	_pcount=ptr._pcount;
	//	//	++*_pcount;
	//	//}
	//	swap(_ptr,ptr._ptr);
	//	swap(_pcount,ptr._pcount);
	//	return *this;
	//}
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
	D _del;
protected:
	void Release()
	{
		if(--*_pcount==0)
		{
			delete _pcount;
			_del(_ptr);
			//delete _ptr;
		}
	}
};
//template<class T>
struct Free
{
	void operator()(void* ptr)
	{
		cout<<"free:"<<free<<endl;
		free(ptr);
	}
};
template<class T>
struct DefaultDel
{
	void operator()(T* ptr)
	{
		delete ptr;
	}
};
struct Fclose
{
	void operator()(void *ptr)
	{
		cout<<"Fclose:"<<ptr<<endl;
		fclose((FILE *)ptr);
	}
};

