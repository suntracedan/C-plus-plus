#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

unsigned long long Fib1(size_t n)
{
	return n<2?n:Fib1(n-1)+Fib1(n-2);
}
unsigned long long Fib2(size_t n)
{
	unsigned long long first=0;
	unsigned long long second=1;
	unsigned long long result=0;

	if(n<2)
		return n;
	else
	{
		for(size_t i=2;i<=n;i++)
		{
		   result=first+second;
		   first=second;
		   second=result;
		}
		return second;
	}
}
unsigned long long Fib3(size_t n)
{
	if(n<2)
		return n;
	else
		return Fib3(n-1)+Fib3(n-2);
}
unsigned long long Fib(size_t n)
{
	unsigned long long *a=new unsigned long long[n+1];
	a[0]=0;
	a[1]=1;
	for(size_t i=2;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
		
	}
	return a[n];
}

template<class T> 
class Stack
{
public:
	Stack()
		:_top(0)
		,_capacity(0)
		,_a(NULL)
	{
	}
	~Stack()
	{
		Pop();
		delete _a;
	}
	void Push(const T& a)
	{
		CheckCapacity();
		_a[_top++]=a;	
	}
	void Pop()
	{
		assert(_top>0);
		_top--;
	}
	T& Top()
	{
		assert(_top>0);
		return _a[_top-1];
	}
	size_t size()
	{
		return _top;
	}
	bool Empty()
	{
		return _top==0;
	}
private:
	T* _a;
	size_t _top;
	int _capacity;
protected:
	void CheckCapacity()
	{
		//if(_a==NULL)
		//{
		//	_capacity=3;
		//	_a=new T[_capacity];
		//	return;
		//}
		//else
		//_capacity=2*_capacity;
	      if(_top==_capacity)
	      {
		      _capacity=2*_capacity+1;
		      T* tmp=new T[_capacity];
		      for(size_t i=0;i<_top;i++)
		      {
			    tmp[i]=_a[i];
		      }
			   delete[] _a;
			   _a=tmp;
	       }
	}
};