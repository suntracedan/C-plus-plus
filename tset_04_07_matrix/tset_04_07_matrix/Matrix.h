#pragma once
#include<iostream>
#include<vector>
using namespace std;
template<class T>
class SymnetricMatrix
{
public:
	SymnetricMatrix(T* a,size_t size)
		:_a(new T[size*(size+1)/2])
		,_size(size*(size+1)/2)
		,_n(size)
	{
		size_t index=0;
		for(size_t i=0;i<_n;i++)
		{
			for(size_t j=0;j<_n;j++)
			{
				if(i>=j)
				{
					_a[index++]=a[i*_n+j];
				}
				else
				{
					break;
				}
			}
		}
	}
	~SymnetricMatrix()
	{
		if(_a)
		{
			delete[] _a;
			_a=NULL;
			_size=0;
		}
	}
	void Display()
	{
		for(size_t i=0;i<_n;i++)
		{
			for(size_t j=0;j<_n;j++)
			{
				if(i>=j)
				{
					cout<<_a[i*(i+1)/2+j]<<" ";
				}
				else
			    {
					cout<<_a[j*(j+1)/2+i]<<" ";
				}
			}
			cout<<endl;
		}
	}
	SymnetricMatrix(size_t i,size_t j)
	{
		if(i<j)
		{
			swap(i,j);
			return _a[i*(i+1)/2+j];
		}
	}
protected:
	T* _a;
	size_t _size;
	size_t _n;
};


template<class T>
struct Triple
{
	size_t _row;
	size_t _col;
	T _value;
	Triple(const T& value=T(),size_t row=0,size_t col=0)
		:_value(value)
		,_col(col)
		,_row(row)
	{
	}
	//Triple()
	//	:_col(0)
	//	,_row(0)
	//{}
};
template<class T>
class SparseMatrix
{
public:
	SparseMatrix(T* a,size_t m,size_t n,const T& invalued)
		:_invalued(invalued)
		,_rowsize(m)
		,_colsize(n)
	{
		for(size_t i=0;i<m;i++)
		{
			for(size_t j=0;j<n;j++)
			{
				if(a[i*n+j]!=invalued)
				{
					_a.push_back(Triple<T>(a[i*n+j],i,j));
				}
			}
		}
	}
	SparseMatrix()
		:_invalued(0)
		,_colsize(0)
		,_rowsize(0)
	{}
	void Display()
	{
		size_t index=0;
		for(size_t i=0;i<_rowsize;i++)
		{
			for(size_t j=0;j<_colsize;j++)
			{
				if(index<_a.size()&&_a[index]._row==i&&_a[index]._col==j&&_a[index]._value!=_invalued)
				{
					cout<<_a[index]._value<<" ";
					index++;
				}
				else
				{
					cout<<_invalued<<" ";
				}
				
			}

			cout<<endl;
		}
	}
	SparseMatrix<T> TranSport()
	{
		SparseMatrix<T> tmp;
		tmp._rowsize=_rowsize;
		tmp._colsize=_colsize;
		tmp._invalued=_invalued;
		
		for(size_t i=0;i<_colsize;i++)
		{
				size_t index=0;
				while(index<_a.size())
				{
					if(_a[index]._col==i)
					{
						Triple<T> t;
						t._value=_a[index]._value;
						t._row=_a[index]._col;
						t._col=_a[index]._row;
						tmp._a.push_back(t);
					}
					index++;
				}	
			}
		return tmp;
	}
	SparseMatrix<T> FastPort()
	{
		SparseMatrix<T> tmp;
		tmp._rowsize=_rowsize;
		tmp._colsize=_colsize;
		tmp._invalued=_invalued;
		int *rowcount=new int[_colsize];
		int *rowstart=new int[tmp._rowsize];
		memset(rowcount,0,sizeof(int)* _colsize);
		memset(rowstart,0,sizeof(int)* _colsize);
		size_t index=0;
		while(index<_a.size())
		{
			rowcount[_a[index]._col]++;
			index++;
		}
		rowstart[0]=0;
		//每一列第一个有效值的位置
		for(size_t i=1;i<_colsize;i++)
		{
			rowstart[i]=rowstart[i-1]+rowcount[i-1];
		}
		index=0;
		tmp._a.resize(_a.size());//开辟一个size大的空间，并初始化
		while(index<_a.size())
		{
			size_t rowindex=_a[index]._col;
			int& start=rowstart[rowindex];
			Triple<T> t;
			t._value=_a[index]._value;
			t._row=_a[index]._col;
			t._col=_a[index]._row;
			tmp._a[start++]=t;
			index++;
		}
		return tmp;

	}

protected:
	vector<Triple<T> > _a;
	size_t _rowsize;
	size_t _colsize;
	T _invalued;
};
