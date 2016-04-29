#pragma once
#include<iostream>
using namespace std;

template<class T>
struct BinaryTreeThdNode
{
	T _data;
	BinaryTreeThdNode<T>* _left;
	BinaryTreeThdNode<T>* _right;
	T* _LefTag;
	T* _RightTag;
	BinaryTreeThdNode(const T& x)
		:_data(x)
		,_left(NULL)
		,_right(NULL)
		,_LeftTag(LINK)
		,_RightTag(LINK)
	{}
};
enum
{
	LINK,
	THREAD,
};
template<class T>
class BinaryTreeThd
{
	typedef BinaryTreeThdNode<T> Node;
public:
	BinaryTreeThd()
		:_root(NULL)
	{}
	BinaryTreeThd(const T* a,size_t size,const T& invalid,size_t index=0)
	{
		_root=_CreateTree(a,size,invalid,index);
		return _root;
	}
	void InorderThreading()
	{
		Node* prev=NULL;
		_InorderThreading(_root);
	}
	void InorderThd()
	{
		Node* cur=_root;
		while(cur)
		{
			while(cur->_LefTag==LINK)
			{
				cur=cur->_left;
			}
			cout<<cur->_data<<" ";
			while(cur->_right==THREAD)
			{
				cur=cur->_right;
				cout<<cur->_data<<" ";
			}
			cur=cur->_right;
		}
		cout<<endl;
	}
public:
	Node* _CreateTree(const T* a,size_t size,const T& invalid,size_t index)
	{
		Node* root=NULL;
		if(index<size&&a[index]!=invalid)
		{
			root=new Node(a[index]);
			root->_left=_CreateTree(a,size,invalid,++index);
			root->_right=_CreateTree(a,size,invalid,++index);
		}
		return root;
	}
	void _InorderThreading(Node* cur)
	{
		if(cur==NULL)
		{
			return;
		}
		_InorderThreading(cur->_left);
	}
protected:
	Node* _root;

};