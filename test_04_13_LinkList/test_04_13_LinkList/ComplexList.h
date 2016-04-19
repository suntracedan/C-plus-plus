#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>
struct Node
{
	Node<T>(T d)
		:_data(d)
		,_next(NULL)
		,_random(NULL)
	{
	}
	T _data; 
	Node<T>* _next;
	Node<T>* _random;
};

template<class T>
class ComplexList
{
public:
	ComplexList()
		:_head(NULL)
		,_tail(NULL)
	{
	}
	~ComplexList()
	{
		Node<T>* cur=_head;
		while(cur)
		{
			Node<T>* del=cur;
			cur=cur->_next;
			delete del;
		}
	}
	ComplexList(const ComplexList& cl)
		:_head(NULL)
		,_tail(NULL)
	{
		Node<T>*cur=cl._head;
		while(cur)
		{
			PushBack(cur->_data);
			cur=cur->_next
		}
	}
	void PushBack(T d)
	{
		Node<T>* newnode=new Node<T>(d);
		if(_head==NULL)
		{
			_head=newnode;
			_tail=_head;
		}
		else
		{
			_tail->_next=newnode;
			_tail=newnode;
		}
	}
	ComplexList* Listcpy2(ComplexList* cl)
	{
		Node<T>* cur=cl->_head;
		//复制链表
		while(cur)
		{
			Node<T>* tmp=new Node(cur->_data);
			tmp->_next=cur->_next;
			cur->_next=tmp;
			cur=tmp->_next;
		}
		cur=cl->_head;
		//置它的random
		while(cur)
		{
			if(cur->_random!=NULL)
			{
				Node<T>* next=cur->_next;
				next->_random=cur->_random->_next;
				cur=cur->_next->_next;
			}			
		}
		cur=cl->_head;
		Node<T>* newhead=NULL;
		Node<T>* newtail=NULL;
		if(cur)//置头结点和尾节点
		{
			newhead=newtail=cur->_next;
			cur->_next=newhead->_next;
			cur=cur->_next;
		}
		while(cur)
		{
			newtail->_next=cur->_next;
			newtail=newtail->_next;
			cur->_next=newtail->_next;
			cur=cur->_next;
		}
		return newhead;

	}
	ComplexList& ListCpy(ComplexList& cl)
	{   
		Node<T>* cur=cl._head;
	    Node<T>* cur1=_head;
		while(cur->_next!=NULL)
		{	
			cur1->_data=cur->_data;
			cur1->_next=cur->_next;
			if(cur->_random==NULL)
			{			
				cur1->_random=NULL;
			}
			else
			{
				Node<T>* cur4=cur;
				int count=1;
				cur4=cur->_next;
				//遍历找出C1当前节点的random指针指向的位置，并用一个计数器
				//记录遍历的次数
				while(cur->_random!=cur4)
				{
					if(cur4->_next==NULL)
					{
						cur4->_next=_head;
						count++;
					}
					else 
					{
						count++;
						
					}
					cur4=cur4->_next;
				}
				//通过对计数器的--；找到this当前节点random的指针位置，并赋值
				Node<T>* cur2=cur1;
				while(count)
				{
					cur2=cur2->_next;
					if(cur2==NULL)
					{
						cur2=_head;
					}
					count--;
				}
				cur1->_random=cur2;
			}
			//让当前指针指向下一个位置
			cur=cur->_next;
			cur1=cur1->_next;
			//在上面的代码中，我们有可能改掉了C1的最后一个节点的next,让它指向了第一个节点，
			//所以此处将其的next重新置空
			if(cur->_next==_head)
			{
				cur->_next=NULL;
			}
		}
		return *this;
	}
	void Print(ComplexList&
				cl)
	{
		Node<T>* cur=_head;
		while(cur)
		{
			if(cur->_random==NULL)
			{	
				cout<<cur->_data<<"->";
			}
			else
			{
				cout<<cur->_data<<"->"<<"Ran:"<<cur->_random->_data<<" ";
			}
			cur=cur->_next;
		}

		cout<<"over";
		cout<<endl;
	}
	//这个函数可用于对C1中节点的random指向进行设定
	void SetRandom(ComplexList& cl,int n=-1,int count=0)
	{
		Node<T>* cur1=_head;
		if(n==-1||count==0)
		{
			return;
		}
		while(n--)
		{
			cur1=cur1->_next;
		}
		Node<T>* cur2=cur1;
		while(count--)
		{				
			if(cur2->_next==NULL)
			{
				cur2=_head;
			}
			else
			{
				cur2=cur2->_next;
			}
		}
		cur1->_random=cur2;
	}



private:
	Node<T>* _head;
	Node<T>* _tail;
	//Node<T>* _record;
};

