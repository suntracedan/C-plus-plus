#include"test.h"

template<class T>
class SeqList
{
public:
	SeqList()
		:_data(NULL)
		,_size(0)
		,_capacity(0)
	{
	}
	~SeqList()
	{
		if(_data!=NULL)
			delete[]_data;
	}
	void PushBack(T d);

	void PushFront(T d)
	{
		CheckCapacity();
		int tmp=_size;
		while(tmp)
		{
			_data[tmp]=_data[tmp-1];
			tmp--;
		}
		_data[0]=d;
		_size++;
	}
	void PopBack()
	{
		CheckCapacity();
		if(_size==0)
			cout<<"顺序表已空"<<endl;
		else
			_size--;
	}
	void PopFront()
	{
		int i=0;
		CheckCapacity();
		if(_size==0)
			cout<<"顺序表已空"<<endl;
		else
			for(i=0;i<_size;i++)
			{
				_data[i]=_data[i+1];
			}
			_size--;
	}
	void insert(int pos,T d)
	{
		int tmp=_size;
		while(tmp>pos)
		{
			_data[tmp]=_data[tmp-1];
			tmp--;
		}
		_data[pos]=d;
		_size++;
	}
	void Reverse()
	{
		int end=_size-1;
		int start=0;
		int tmp=0;
		while(end>start)
		{
			tmp=_data[start];
			_data[start]=_data[end];
			_data[end]=tmp;
			end--;
			start++;
		}
	}
	T Find(T d)
	{
		int i=0;
		for(i=0;i<_size;i++)
		{
			if(_data[i]==d)
				{return d;
			break;}
		}
	}
	void Sort()
	{
		int i=0;
		int j=0;
		int tmp=0;
		for(i=0;i<_size;i++)
			for(j=0;j<_size-i-1;j++)
			{
				if(_data[j]>_data[j+1])
				{
					tmp=_data[j];
					_data[j]=_data[j+1];
					_data[j+1]=tmp;
				}
			}
	}


	void Print()
	{
		int i=0;
		for(i=0;i<_size;i++)
		{
			cout<<_data[i]<<" ";
		}
		cout<<endl;

	}
	void CheckCapacity()
	{
		if(_size==_capacity)
		{
			T* tmp=new T[2*_capacity+3];
			if(TypeTraits<T>::isPODType().Get())
			{
				memcpy(tmp,_data,_size*sizeof(T));
			}
			else
			{			
				int i=0;
			    for(i=0;i<_size;i++)
				{
					tmp[i]=_data[i];
				}
			}
			delete[] _data;
			_data=tmp;
			_capacity=2*_capacity+3;
		}
	}
private:
	T *_data;
	int _size;
	int _capacity;
};
template<class T>
void SeqList<T>::PushBack(T d)
{
	CheckCapacity();
	_data[_size]=d;
	_size++;
}
void Test1()
{
	SeqList<int>seq;
	seq.PushBack(4);
	seq.PushBack(5);
	//seq.PushBack("l");
   //seq.PushBack("l");
	//seq.PushFront("hi");
	/*seq.PopBack();
	seq.PopFront();*/
	seq.Print();
}
void Test2()
{
	SeqList<int>seq;
	seq.insert(2,5);
	seq.Reverse();
	seq.Print();
}
void Test3()
{
	SeqList<int>seq;
	int ret;
	ret=seq.Find(2);
	//cout<<ret<<endl;
	seq.Sort();
	seq.Print();
}

int main()
{
	Test1();
	//SeqList<string>seq;
	//seq.PushBack("hello");
	//seq.PushBack("444444444444444444444444444444444444444444444");
	//seq.PushBack("11111111111111");
	//seq.PushBack("222222222222");
	//seq.Print();
	/*Test2();
	Test3();*/
	//SeqList<string>seq;
	//seq.PushBack("h");
	getchar();
	return 0;
}
