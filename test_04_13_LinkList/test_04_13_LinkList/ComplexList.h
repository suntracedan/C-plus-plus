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
		//��������
		while(cur)
		{
			Node<T>* tmp=new Node(cur->_data);
			tmp->_next=cur->_next;
			cur->_next=tmp;
			cur=tmp->_next;
		}
		cur=cl->_head;
		//������random
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
		if(cur)//��ͷ����β�ڵ�
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
				//�����ҳ�C1��ǰ�ڵ��randomָ��ָ���λ�ã�����һ��������
				//��¼�����Ĵ���
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
				//ͨ���Լ�������--���ҵ�this��ǰ�ڵ�random��ָ��λ�ã�����ֵ
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
			//�õ�ǰָ��ָ����һ��λ��
			cur=cur->_next;
			cur1=cur1->_next;
			//������Ĵ����У������п��ܸĵ���C1�����һ���ڵ��next,����ָ���˵�һ���ڵ㣬
			//���Դ˴������next�����ÿ�
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
	//������������ڶ�C1�нڵ��randomָ������趨
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

