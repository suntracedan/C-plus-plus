#include"ComplexList.h"

int main()
{
	ComplexList<int> c1;
	ComplexList<int> c2;
	c1.PushBack(2);
	c1.PushBack(3);
	c1.PushBack(4);
	c1.PushBack(5);		
	//c1.Print(c1);
	//c1.SetRandom(c1);
	c1.SetRandom(c1,2,3);
	c1.SetRandom(c1,1,4);
	c1.Print(c1);
	c2=c1.ListCpy(c1);
	getchar();
	return 0;
}

