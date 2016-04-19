#include"SeqList.h"
void InitSeq(pSeqList pSeq)
{
	assert(pSeq);
	pSeq->Data=(DataType *)malloc(INT*sizeof(DataType));
	memset(pSeq->Data,0,INC*sizeof(DataType));
	pSeq->capacity=INC;
	pSeq->size=0;
}
void CheckCapacity(pSeqList pSeq)
{
	if(pSeq->size>=INT)
	{
		pSeq->Data=(DataType*)realloc(pSeq->Data,(pSeq->capacity+INC)*sizeof(int));
		pSeq->capacity+=INC;
	}
}
void Push_Back(pSeqList pSeq,DataType d)
{
	
	CheckCapacity(pSeq);
	pSeq->Data[pSeq->size]=d;
	pSeq->size++;
}
void PrintSeqList(pSeqList pSeq)
{
	int i=0;
	for(i=0;i<pSeq->size;i++)
	{
		printf("%d ",pSeq->Data[i]);
	}
}
void Pop_Back(pSeqList pSeq)
{
	if(pSeq->size==0)
	{
		printf("Á´±íÒÑ¿Õ");
	}
	else
		pSeq->size--;
}
void Push_Front(pSeqList pSeq,DataType d)
{
	int i=pSeq->size;
	while(i)
	{
		pSeq->Data[i]=pSeq->Data[i-1];
		i--;
	}
	pSeq->Data[0]=d;
	pSeq->size++;
}
void Pup_Front(pSeqList pSeq)
{

}
