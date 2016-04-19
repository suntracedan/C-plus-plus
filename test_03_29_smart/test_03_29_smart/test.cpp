#include"SmartPtr.h"


void Test1()
{
	int *p1=new int(1);
	int *p3=new int(1);
	//string *p1=new string("hello ");
	//string *p2=new string("world");
	AutoPtr<int> sa(p1);
	AutoPtr<int> sc(p3);
	/*AutoPtr<A> sa1(new A[10]);
	sa1->_b;*/
}

void Test2()
{
	int *p1=new int(1);
	int *p3=new int(1);
	ScopedPtr<int> sa(p1);
	//ScopedPtr<int> p2(sa);
	
}
void Test3()
{
	//int *p1=new int(2);
	//int *p2=new int(3);
	//int *p3=p2;
	string *pa=new string("hello");
	string *pb=new string("wprld");
	SharedPtr<string> sa(pa);
	SharedPtr<string> sc(pb);
	//sa=sc;

	//sa=pa;
	/*long ret=pa.Usecount();
	cout<<*sa<<endl;*/
}
void Test4()
{
	ScopedArr<A> sa(new A[10]);
	sa[1]._b=10;
	sa[2]._b=11;
	sa[1]._a=20;
	cout<<sa[1]._a<<" "<<sa[1]._b<<endl;
}

void Test5()
{
	////SharedArr<A> sa(new A[10]);
	////sa[1]._a=20;
	////sa[1]._b=30;
	int *p1=new int[10];
	p1[10]=10;
	int *p2=new int[20];
	SharedArr<int> sp(p1);
	SharedArr<int> ap(sp);
	SharedArr<int> mp(sp);
	long ret=mp.Usecount();
	int* p4=mp.GetPtr();
	int* p5=ap.GetPtr();
	int* p6=sp.GetPtr();
	cout<<p4<<" "<<p5<<" "<<p6<<" "<<endl;
	cout<<ret<<endl;
	cout<<ap[10]<<endl;
}
int main()
{
	Test3();
	getchar();
	return 0;
}