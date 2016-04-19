#include"Matrix.h"

void Test1()
{
	
	int a[5][5]={{0,0,1,0,2},{0,0,3,0,4},{1,3,0,5,0},{0,0,5,0,6},{2,4,0,6,0}};
    SymnetricMatrix<int> sm((int *)a,5);
	sm.Display();
}

void Test2()
{
	int a[5][5]={{1,0,0,0,0},{0,3,0,0,5},{0,0,6,5,0},{0,0,0,0,9},{0,8,0,0,0}};
	SparseMatrix<int> sm((int*)a,5,5,0);
	SparseMatrix<int> am;
	sm.Display();
	am=sm.TranSport();
	cout<<endl;
	am=sm.FastPort();
	am.Display();
}
int main()
{
	Test2();
	getchar();
	return 0;
}
