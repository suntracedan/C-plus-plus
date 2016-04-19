#pragma once
#include<string.h>
typedef int DataType


typedef struct SeqListD
{
	DataType *Date;
	DataType size;
	DataType capacity;
	
}SeqListD,*pSeqList;

void Checkcapacity(pSeqList pSeq);

void PushBack(pSeqList pSeq)
{
	Checkcapacity();
}


	