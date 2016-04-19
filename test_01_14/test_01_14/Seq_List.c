#include"Seq_List.h"
void IntiSeqList(pSeqList pseq)
{
	memset(pseq->arr,0,sizeof(pseq->arr));
	pseq->size=0;
}
void PrintSeqList(SeqList seq)
{
	int i=0;
	for(i=0;i<seq.size;i++)
	{
		printf("%d ",seq.arr[i]);
	}
	printf("over ");
}
void PushBack(pSeqList pseq,DataType d)
{
	if(pseq->size<sizeof(pseq->arr)/4)
	{
		pseq->arr[pseq->size]=d;
		pseq->size+=1;
	}
	return;
}
void PopBack(pSeqList pseq)
{
	if(pseq->size==0)
	{
		return;
	}
		//pseq->arr[pseq->size]=0;
	    pseq->size--;
}
void PushFront(pSeqList pseq,DataType d)
{
	if(pseq->size>=SIZE)
		return;
	if(pseq->size==0)
	{
		pseq->arr[pseq->size]=d;
		pseq->size++;
	}
	else
	{
		int i=pseq->size;
		for(i=pseq->size;i>0;i--)
		{
			pseq->arr[i]=pseq->arr[i-1];

		}
		pseq->arr[0]=d;
		pseq->size++;
	}
	
}
void PopFront(pSeqList pseq)
{
	if(pseq->size==0)
	{
		printf("ÄÚ´æÒÑ¿Õ  ");
	}
	//else if(pseq->size==1)
	//{
	//	pseq->size--;
	//}
	else
	{
		int i=0;
		for(i=0;i<pseq->size;i++)
		{
			pseq->arr[i]=pseq->arr[i+1];
		}
		pseq->size--;
	}
}

void Move(pSeqList pseq,const DataType d)
{
	int i=0;
	while(i<pseq->size)
	{
		if(pseq->arr[i]==d)
		{
			for(i;i<pseq->size;i++)
			{
				pseq->arr[i]=pseq->arr[i+1];
			}
			pseq->size--;
			break;
		}
		else
			i++;
	}

}

int Find(pSeqList pseq,const DataType d)
{
	int i=0;
	for(i=0;i<pseq->size;i++)
	{
		if(pseq->arr[i]==d)
			return i;
	}
}
void Insert(pSeqList pseq,DataType pos,DataType d)
{
	//assert(pseq);
	int i=0;
	if(pseq->size==SIZE)
	{
		return;
	}
	for(i=pseq->size-1;i>=pos;i--)
		{
			pseq->arr[i+1]=pseq->arr[i];
		}
			pseq->arr[pos]=d;
			pseq->size++;
}

void Reverse(pSeqList pseq)
{
	int start=0;
	int end=pseq->size-1;
	while(end>start)
	{
		DataType tmp=pseq->arr[start];
	    pseq->arr[start]=pseq->arr[end];
	    pseq->arr[end]=tmp;
		end--;
		start++;
	}	
}
void Sort(pSeqList pseq)
{
	DataType i=0;
	DataType j=0;
	DataType tmp=0;
	for(i=0;i<(pseq->size-1);i++)
	{
		for(j=0;j<(pseq->size-1-i);j++)
		{
			if(pseq->arr[j]>pseq->arr[j+1])
			{
				tmp=pseq->arr[j];
				pseq->arr[j]=pseq->arr[j+1];
				pseq->arr[j+1]=tmp;
			}
		}
	}
}