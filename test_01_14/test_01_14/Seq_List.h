#ifndef __SEQ_LIST_H__
#define __SEQ_LIST_H__
#endif
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int DataType;
#define SIZE 6
typedef struct SeqList
{
	DataType arr[SIZE];
	DataType size;
}SeqList,*pSeqList;


void IntiSeqList(pSeqList pseq);
void PrintSeqList(SeqList seq);
void PopBack(pSeqList pseq);
void PopFront(pSeqList pseq);
void PushBack(pSeqList pseq,const DataType d);
void PushFront(pSeqList pseq,const DataType d);
void Move(pSeqList pseq,const DataType d);
int Find(pSeqList pseq,const DataType d);
void Insert(pSeqList pseq,DataType pos,DataType d);
void Reverse(pSeqList pseq);
void Sort(pSeqList pseq);




