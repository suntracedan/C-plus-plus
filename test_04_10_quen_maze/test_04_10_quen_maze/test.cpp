#include"quen_maze.h"
#define N 10
//void Test1()
//{
//	Queen<int> que;
//	que.Push(4);
//	que.Push(5);
//	que.Push(6);
//	que.Pop();
//	while(que.Empty())
//	{
//		cout<<que.Front()<<" ";
//		que.Pop();
//	}
//}
//void Test2()
//{
//	Cell a[]={{op_num,65},{op_num,1},{op_num,4},
//	{op_symbol,ADD},{op_symbol,SUB}};
//	cout<<"ÔËËã½á¹û:"<<CountRNP(a,sizeof(a)/sizeof(Cell));
//}

void Test3()
{
	int a[N][N]={};
	GetMaze((int*)a,N);
	PrintMaze((int *)a,N);
	Pos entry;
	entry._col=0;
	entry._row=2;
	stack<Pos> path;
	MazePath((int*)a,N,entry,path);
    PrintMaze((int*)a,N);
}
int main()
{
	Test3();
	getchar();
	return 0;
}