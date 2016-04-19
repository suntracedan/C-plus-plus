#include"test_Feb.h"
void Test1()
{
	unsigned long long ret=Fib3(6);
	cout<<ret<<endl;
}

void Test2()
{
		Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	//s.Pop();
	//s.Pop();
	size_t ret=s.size();
	while(!s.Empty())
	{
		cout<<s.Top()<<" ";
		s.Pop();
	}
	cout<<endl;
	cout<<ret<<endl;
}
int main()
{
	//Test1();
	Test2();
	getchar();
	return 0;
}