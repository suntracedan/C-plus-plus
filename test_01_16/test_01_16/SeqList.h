#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define INC 11
#define INT 11
typedef int DataType;
typedef struct SeqListD
{
	DataType *Data;
	int size;
	int capacity;
}SeqList,*pSeqList;
void InitSeq(pSeqList pSeq);
void CheckCapacity(pSeqList pSeq);
void Push_Back(pSeqList pSeq,DataType d);
void Pop_Back(pSeqList pSeq);
void Push_Front(pSeqList pSeq,DataType d);
void Pup_Front(pSeqList pSeq);
void PrintSeqList(pSeqList pSeq);
