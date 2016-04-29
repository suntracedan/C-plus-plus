#pragma once
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	T _data;
	BinaryTreeNode(T d)
		:_data(d)
		,_left(NULL)
		,_right(NULL)
	{}
};

template<class T>
class BinaryTree
{
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T* a,size_t size,size_t index,const size_t invalid)
	{
		_root=_CreateTree(a,size,index,invalid);
	}
	void PreOrder()
	{
		_PreOrder(_root);
		cout<<endl;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}
	void PostOrder()
	{
		_PostOrder(_root);
		cout<<endl;
	}
	size_t Size()
	{
		return _Size(_root);
	}
	size_t Depth()
	{
		return _Depth(_root);
	}
	size_t LeafSize()
	{
		return _LeafSize(_root);
	}
	void LeveOrder()
	{
		queue<BinaryTreeNode<T>*> q;
		if(_root)
		{
			q.push(_root);
		}
		while(!q.empty())
		{
			BinaryTreeNode<T>* front=q.front();
			cout<<front->_data<<" ";
			if(front->_left!=NULL)
			{
				q.push(front->_right);
			}
			if(front->_right!=NULL)
			{
				q.push(front->_left);
			}
			q.pop();
		}
	}
	void PrevOrder_NonR()
	{
		stack<BinaryTreeNode<T>*> s;
		if(_root)
		{
			s.push(_root);
		}
		while(!s.empty())
		{
			BinaryTreeNode<T>* top=s.top();
			cout<<top->_data<<" ";
			s.pop();
			if(top->_right)
			{
				s.push(top->_right);
			}
			if(top->_left)
			{
				s.push(top->_left);
			}
		}
		cout<<endl;
	}
	void InOrder_NonR()
	{
		stack<BinaryTreeNode<T>*> s;
		BinaryTreeNode<T>* cur=_root;
		while(cur||!s.empty())
		{
			while(cur)
			{
				s.push(cur);
				cur=cur->_left;
			}
			BinaryTreeNode<T>* top=s.top();
			cout<<top->_data<<" ";
			s.pop();
			cur=top->_right;
		}
		cout<<endl;
	}
	void PostOrder_NonR()
	{
		BinaryTreeNode<T>* prev=NULL;
		BinaryTreeNode<T>* cur=_root;
		stack<BinaryTreeNode<T>*> s;
		while(cur||!s.empty())
		{
			while(cur)
			{
				s.push(cur);
				cur=cur->_left;
			}
			BinaryTreeNode<T>* top=s.top();
			if(top->_right==NULL||top->_right==prev)
			{
				cout<<top->_data<<" ";
				s.pop();
				prev=top;
			}
			else
			{
				cur=top->_right;
			}
		}
		cout<<endl;
	}
	BinaryTreeNode<T>* Find(const T x)
	{
		return _Find(_root,x);
	}
	size_t GetLevel(size_t k)
	{
		return _GetLevel(_root,k);
	}





protected:
	BinaryTreeNode<T>* _CreateTree(const T* a,size_t size,size_t &index,const T& invalid)
	{
		BinaryTreeNode<T>* root=NULL;
		if(index<size&&a[index]!=invalid)
		{
			root=new BinaryTreeNode<T>(a[index]);
			root->_left=_CreateTree(a,size,++index,invalid);
			root->_right=_CreateTree(a,size,++index,invalid);
		
		}
		return root;
	}
	void _PreOrder(BinaryTreeNode<T>* root)
	{
		if(root==NULL)
			return;
		else
		{
		cout<<root->_data<<" ";
		_PreOrder(root->_left);
		_PreOrder(root->_right);
		}
	}
	void _InOrder(BinaryTreeNode<T>* root)
	{
		if(root->_left)
		{
			_InOrder(root->_left);		
		}
		cout<<root->_data<<" ";
		if(root->_right)
		{
			_InOrder(root->_right);
		}	
	}
	void _PostOrder(BinaryTreeNode<T>* root)
	{
		if(root->_left)
		{
			_PostOrder(root->_left);
		}
		if(root->_right)
		{
			_PostOrder(root->_right);
		}
		cout<<root->_data<<" ";
	}
	size_t _Size(BinaryTreeNode<T>* root)
	{
		size_t size=0;
		if(root)
		{
			size=1;
			size=size+_Size(root->_left)+_Size(root->_right);
		}
		return size;
	}
	size_t _Depth(BinaryTreeNode<T>* root)
	{
		size_t depth=0;
		if(root)
		{
			depth=1+_Depth(root->_left);
			size_t depth1=1+_Depth(root->_right);
			if(depth<depth1)
			{
				depth=depth1;
			}
		}
		return depth;
	}
	size_t _LeafSize(BinaryTreeNode<T>* root)
	{
		if(root==NULL)
		{
			return 0;
		}
		if(root->_left==NULL&&root->_right==NULL)
		{
			return 1;
		}
		return _LeafSize(root->_left)+_LeafSize(root->_right);
	}
	BinaryTreeNode<T>* _Find(BinaryTreeNode<T>* root,const T x)
	{
		if(root==NULL)
		{
			return NULL;
		}
		if(root->_data==x)
		{
			return root;
		}
		BinaryTreeNode<T>* ret=_Find(root->_left,x);
		if(ret)
		{
			return ret;
		}
		else
		{
			return _Find(root->_right,x);
		}
	}
	size_t _GetLevel(BinaryTreeNode<T>* root,size_t k)
	{
		if(root==NULL)
		{
			return NULL;
		}
		if(k==1)
		{
			return 1;
		}
		return _GetLevel(root->_left,k-1)+_GetLevel(root->_right,k-1);
	}
protected:
	BinaryTreeNode<T>* _root;
};