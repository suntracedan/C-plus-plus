#include"BinaryTree.h"

void Test()
{
	int a[]={1,2,'#',3,'#','#',4,5,'#',6,'#',7,'#','#'};
	BinaryTree<int> bt(a,14,0,'#');
	cout<<bt.Find(2)->_data;
	//bt.PreOrder();
	//bt.PrevOrder_NonR();
	//bt.LeveOrder();
	/*bt.InOrder();
	bt.InOrder_NonR();*/
	//bt.PostOrder();
	//bt.PostOrder_NonR();
	//cout<<bt.Size()<<endl;
	//cout<<bt.Depth()<<endl;
	//cout<<bt.LeafSize()<<endl;
}
int main()
{
	Test();
	getchar();
	return 0;
}