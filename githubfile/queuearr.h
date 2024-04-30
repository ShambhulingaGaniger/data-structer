#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct arr
{
	void**st;
	int front,rear,count,size;
}queuearr;
queuearr*creatqueue()
{
	queuearr*q=(queuearr*)malloc(sizeof(queuearr));
	if(q)
	{
		printf("enter teh sizeof the queue\n");
		scanf("%d",&q->size);
		q->st=(void**)calloc(q->size,sizeof(void*));
		if(q->st)
		{
			q->count=0;
			q->front=-1;
			q->rear=-1;
		    return q;
		}
	}
	return NULL;
}
bool queueempty(queuearr*q)
{
	if(q->count==0)
	{
		return true;
	}
	return false;
}
bool queuefull(queuearr*q)
{
	if(q->count==q->front)
	{
		return true;
	}
	return false;
}
bool Enqueue(queuearr*q,void*din)
{
	if(queuefull(q))
	{
		return false;
	}
	if(queueempty(q))
	{
		q->front=0;
	}
	q->rear=(q->rear+1)%q->size;
	q->count++;
	q->st[q->rear]=din;
	return true;
}
void* Dequeue(queuearr*q)
{
	void*dout;
	if(queueempty(q))
	{
		return NULL;
	}
	dout=q->st[q->front];
	q->front=(q->front+1)%q->size;
	q->count--;
	if(q->count==0)
	{
		q->front=-1;
		q->rear=-1;
	}
	return dout;
}
void *retrive_front(queuearr*q)
{
	if(queueempty(q))
	{
		return NULL;
	}
	return q->st[q->front];
}
void *retrive_rear(queuearr*q)
{
	if(queueempty(q))
	{
		return NULL;
	}
	return q->st[q->rear];;
}
int queuecount(queuearr*q)
{
	return q->count;
}
void queuedisplay(queuearr*q,void(*pf)(void*))
{
	for(int i=q->front;i<=q->rear;i=(i+1)%q->size)
	{
		pf(q->st[i]);
	}
}
bool queuedestroy(queuearr*q)
{
	if(q){
	void *d;
	for(int i=q->front;i<=q->rear;i=(i+1)%q->size)
	{
		d=q->st[i];
		free(d);
	}
	free(q->st);
	free(q);
	return true;}
	return false;
}
	
	

