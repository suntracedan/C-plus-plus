#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>

template<class T>
struct Node
{
	T _data;
	Node* _next;
	Node(const T& x)
		:_data(x)
		,_next(NULL)
	{}
};
template<class T>
class Queen
{
public:
	Queen()
		:_head(NULL)
		,_tail(_head)
		,_size(0)
	{
	}
	~Queen()
	{
		cout<<"xigou"<<endl;
	}
	Queen(const Queen<T>& ap)
		:_head(ap._head)
		,_tail(ap._tail)
		,_size(ap._size)
	{
	}
	void Push(const T& d)
	{
		if(_head==NULL)
		{
			_head=_tail=new Node<T>(d);
		}
		else
		{
			_tail->_next=new Node<T>(d);
			_tail=_tail->_next;
		}
		_size++;
	}
	void Pop()
	{
		if(_head==NULL)
		{
			cout<<"队列已满"<<endl;
		}
		Node<T>* del=_head;
		_head=_head->_next;
		delete del;
		_size--;
	}
	T& Front()
	{
		assert(_head);
		return _head->_data;
	}
	T& Back()
	{
		assert(_tail);
		return _tail->_next;
	}
	bool Empty()
	{
		if(_size==0)
		{
			return false;
		}
		else
			return true;
	}
	size_t Size()
	{
		return _size;
	}
protected:
	Node<T>* _head;
	Node<T>* _tail;
	size_t _size;
};

enum Type
{
	op_num,
	op_symbol,
};
enum SYMBOL
{
	ADD,
	SUB,
	MUL,
	DIV,
};
struct Cell
{
	Type _type;
	int _value;
};
stack<int> s;
int CountRNP(Cell* a,size_t size)
{
	assert(a);
	for(size_t i=0;i<size;i++)
	{
		if(a[i]._type==op_num)
		{
			s.push(a[i]._value);
		}
		else
		{
			int right=s.top();
			s.pop();
			int left=s.top();
			s.pop();
			switch(a[i]._value)	
			{
			case ADD:
				{
					s.push(left+right);
				    break;
				}
			case SUB:
				{
					s.push(right-left);
					break;
				}
			case MUL:
				{
					s.push(right*left);
					break;
				}
			case DIV:
				{
					s.push(right/left);
					break;
				}
			}		
		}	
	}
	return s.top();
}



struct Pos
{
	int _row;
	int _col;
};
void GetMaze(int* a,int n)
{
	FILE* fout=fopen("MazeMap.txt","r");
	assert(fout);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;)
		{		
			char ch=fgetc(fout);
			if(ch=='0'||ch=='1')
			{
				a[i*n+j]=ch-'0';
				j++;
			}
			else
			{
				continue;
			}
		}

	}
	fclose(fout);
}
void PrintMaze(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i*n+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
bool CheckIsAccess(int *a,int n,Pos next)
{
	assert(a);
	if(next._row>=0&&next._row<n&&next._col>=0&&next._col<n
		&&(a[next._row*n+next._col]==0))
	{
		return true;
	}
	else
		return false;
}
bool MazePath(int* a,int n,const Pos& entry,stack<Pos>& path)
{
	Pos cur=entry;
	path.push(cur);
	while(!path.empty())
	{
		a[cur._row*n+cur._col]=2;
		if(cur._row==n-1)
		{
			return true;
		}
		else
		{		
			//上
		    Pos next=cur;
		    next._row--;
		    if(CheckIsAccess(a,n,next))
			{
				cur=next;
				path.push(cur);
				continue;
			}
			next=cur;
			next._col++;
			if(CheckIsAccess(a,n,next))
			{
				cur=next;
				path.push(cur);
				continue;
			}
			//下
			next=cur;
			next._row++;
			if(CheckIsAccess(a,n,next))
			{
				cur=next;
				path.push(cur);
				continue;
			}
			//左
			next=cur;
			next._col--;
			if(CheckIsAccess(a,n,next))
			{
				cur=next;
				path.push(cur);
				continue;
			}
		    cur=path.top();
			path.pop();
		}			

	}
}
