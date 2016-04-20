#include"GeneraLized.h"

void Test1()
{
	GeneraLized g1("(1,(2,3),4,(1,2,(2,(4,5))))");
	GeneraLized g3("(3,4)");
	size_t ret=g3.Depth();
	g3=g1;
	//GeneraLized g2(g1);
	g3.print();
	/*=gl.Size();*/
	cout<<ret;
}
int main()
{
	Test1();
	getchar();
	return 0;
}