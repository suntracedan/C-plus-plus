#include"Seq_List.h"
void Test1()
{
	SeqList mySeq;
	IntiSeqList(&mySeq);
	PushBack(&mySeq,9);
	PushBack(&mySeq,10);
	PushBack(&mySeq,11);
	PrintSeqList(mySeq);
	PushBack(&mySeq,12);
	PopBack(&mySeq);
	PrintSeqList(mySeq);
}
void Test2()
{
	SeqList mySeq;
	IntiSeqList(&mySeq);
	PopFront(&mySeq);
	PrintSeqList(mySeq);
	PushFront(&mySeq,4);
	PrintSeqList(mySeq);
	PushFront(&mySeq,3);
	PushFront(&mySeq,2);
	PopFront(&mySeq);
	PushFront(&mySeq,1);
	PrintSeqList(mySeq);
}
void Test3()
{
	SeqList mySeq;
	IntiSeqList(&mySeq);
	PushFront(&mySeq,1);
	PushFront(&mySeq,2);
	PushFront(&mySeq,3);
	PushFront(&mySeq,6);
	PushFront(&mySeq,5);
	Sort(&mySeq);
	//Reverse(&mySeq);
	//Insert(&mySeq,3,5);
	//Move(&mySeq,3);
	PrintSeqList(mySeq);	
}
int main()
{
    Test3();
	getchar();
	return 0;
}