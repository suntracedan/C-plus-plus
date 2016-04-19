#include"SeqList.h"

void Test()
{
	SeqList mypseq;
	InitSeq(&mypseq);
	Push_Back(&mypseq,1);
	Push_Back(&mypseq,2);
	Push_Back(&mypseq,3);
	Push_Back(&mypseq,4);
	Push_Front(&mypseq,0);
	PrintSeqList(&mypseq);
}
int main()
{
	Test();
	getchar();
	return 0;
}