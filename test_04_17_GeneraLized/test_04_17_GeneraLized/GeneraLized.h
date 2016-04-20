#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

enum Type
{
	HEAD,
	VALUE,
	SUB,
};

struct GeneraLizedNode
{
	Type _type;
	GeneraLizedNode *_next;

	union
	{
		char _value;
		GeneraLizedNode *_sublink;
	};
	GeneraLizedNode(Type type=HEAD,char value=0)
		:_type(type)
		,_next(NULL)
	{
		if(_type==VALUE)
		{
			_value=value;
		}
		else if(_type==SUB)
		{
			_sublink=NULL;
		}
	}
};


class GeneraLized
{
public:
	GeneraLized()
		:_head(new GeneraLizedNode(HEAD))
	{}
	GeneraLized(const char* str)
	{
		_head= CreateLized(str);
	}
	~GeneraLized()
	{
		_Destory(_head);
		_head=NULL;
	}
	GeneraLized(const GeneraLized& g)
	{
		_head=_Copy(g._head);
	}
	//GeneraLized& operator=(const GeneraLized& g)
	//{
	//	if(this!=&g)
	//	{
	//		GeneraLizedNode* tmp=_Copy(g._head);
	//		_Destory(_head);
	//		_head=tmp;
	//	}
	//	return *this;
	//}
	GeneraLized& operator=(GeneraLized g)
	{
		swap(_head,g._head);
		return *this;
	}
	void print()
	{
		_print(_head);
		cout<<endl;
	}
	size_t Size()
	{
		return _Size(_head);
	}
	size_t Depth()
	{
		return _Depth(_head);
	}
protected:
	GeneraLizedNode* CreateLized(const char* &str)//用引用局部改变，则这个变量都会改变
	{
	    assert(str&&*str=='(');
		str++;
		GeneraLizedNode *head=new GeneraLizedNode(HEAD);
		GeneraLizedNode *cur=head;
		while(*str)
		{
			if(_Isvalue(*str))
			{
				cur->_next=new GeneraLizedNode(VALUE,*str);
				cur=cur->_next;
				str++;
			}
			else if(*str=='(')
			{
				cur->_next=new GeneraLizedNode(SUB);
				cur=cur->_next;
				cur->_sublink=CreateLized(str);
			}
			else if(*str==')')
			{
				str++;
				return head;
			}
			else
			{
				++str;
			}	
		}
		assert(false);
		return head;
	}
	bool _Isvalue(char ch)
	{
		if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void _Destory(GeneraLizedNode* head)
	{
		GeneraLizedNode* cur=head;
		while(cur)
		{
			GeneraLizedNode* del=cur;
			cur=cur->_next;
			if(del->_type==SUB)
			{
				_Destory(del->_sublink);
			}
			else
				delete del;
		}
	}

	GeneraLizedNode* _Copy(GeneraLizedNode* head)
	{
		//assert(head->_type===HEAD);
		GeneraLizedNode* newhead=new GeneraLizedNode(HEAD);
		GeneraLizedNode* cur=head->_next;
		GeneraLizedNode* newcur=newhead;
		while(cur)
		{
			if(cur->_type==VALUE)
			{
				newcur->_next=new GeneraLizedNode(VALUE,cur->_value);
				newcur=newcur->_next;
			}
			else if(cur->_type==SUB)
			{
				newcur->_next=new GeneraLizedNode(SUB);
				newcur=newcur->_next;
				newcur->_sublink=_Copy(cur->_sublink);
			}
			cur=cur->_next;
		}
		return newhead;
	}

	size_t _Depth(GeneraLizedNode* head)
	{
		size_t depth=1;
		GeneraLizedNode* cur=head;
		while(cur)
		{
			if(cur->_type==SUB)
			{
				size_t newdepth=0;
				newdepth=1+_Depth(cur->_sublink);
				if(newdepth>depth)
				{
					depth=newdepth;
				}
			}
			cur=cur->_next;
		}
		return depth;
	}

	size_t _Size(GeneraLizedNode* head)
	{
		size_t size=0;
		GeneraLizedNode* cur=head;
		while(cur)
		{
			if(cur->_type==VALUE)
			{
				size++;
			}
			else if(cur->_type==SUB)
			{
				size+=_Size(cur->_sublink);
			}
			cur=cur->_next;
		}
		return size;
	}

	void _print(GeneraLizedNode* head)
	{
		GeneraLizedNode* cur=head;
		while(cur)
		{
			if(cur->_type==HEAD)
			{
				cout<<"(";
			}
			else if(cur->_type==VALUE)
			{
				cout<<cur->_value;
				if(cur->_next)
				{
					cout<<",";
				}
			}
			else
			{
				_print(cur->_sublink);
				if(cur->_next)
				{
					cout<<",";
				}
			}
			cur=cur->_next;
		}
		cout<<")";
	}
protected:
	GeneraLizedNode* _head;
};