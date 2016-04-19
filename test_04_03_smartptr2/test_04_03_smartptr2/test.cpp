#include"smartptr2.h"

void Test1()
{
	AutoPtr<int> s1(new int(1));
	AutoPtr<int> s2(s1);

	 s1=s2;
	//*s2=9;AutoPtr<int>*/
	//AutoPtr<A> ap(new A[sizeof(A)]);
	//ap->_a=0;
}

void Test_SharedPtr()
{
	//int *p1=(int*)malloc(sizeof(int)*10);
	//shared_ptr<int> sp1(p1,Free());
	SharedPtr<int,DefaultDel<int>> ap(new int(1));
	SharedPtr<int,DefaultDel<int>> ap2=ap;

	/*FILE* p2=fopen("test.cpp","r");
	shared_ptr<FILE> sp2(p2,Fclose());*/
}
int main()
{
	//Test1();
	Test_SharedPtr();
	getchar();
	return 0;
}