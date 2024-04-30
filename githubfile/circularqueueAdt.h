#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
	void*dp;
	struct Node *next;
}node;
typedef struct Q
{
	node*front,*rear;
	int count;
}queue;
bool queueempty(queue*q)
{
	if(q->count==0)
	{
		return true;
	}
	return false;
}
bool queuefull()
{
	node*temp=(node*)malloc(sizeof(node));
	if(temp)
	{
		return false;
	}
	return true;
}
queue*creatqueue()
{
	queue*q=(queue*)malloc(sizeof(queue));
	if(q)
	{
		q->front=NULL;
		q->rear=NULL;
		q->count=0;
		return q;
	}
	return NULL;
}
bool  Enqueue(queue*q,void*din)
{
	node*newnode=(node*)malloc(sizeof(node));
	if(newnode)
	{
		newnode->dp=din;
		if(queueempty(q))
		{
			q->front=newnode;
		}
		else
		{
			q->rear->next=newnode;
		}
		q->rear=newnode;
		newnode->next=q->front;
		q->count++;
		return true;
	}
	return false;
}
void*Dequeue(queue*q)
{
	node*newnode;
	void*dout;
	if(queueempty(q))
	{
		return NULL;
	}
	if(q->count==1)
	{
		q->rear=NULL;
		newnode=q->front;
		dout=newnode->dp;
		q->front=NULL;
		q->count--;
		free(newnode);
		return dout; 
	}
	newnode=q->front;
	q->front=newnode->next;
	q->rear->next=q->front;
	dout=newnode->dp;
	q->count--;
	free(newnode);
	return dout;
}
void *retrive_front(queue*q)
{
	if(queueempty(q))
	{
		return NULL;
	}
	return q->front->dp;
}
void *retrive_rear(queue*q)
{
	if(queueempty(q))
	{
		return NULL;
	}
	return q->rear->dp;
}
int queuecount(queue*q)
{
	return q->count;
}
void queuedisplay(queue*q,void(*pf)(void*))
{
	node*temp=q->front;
	while(temp->next!=q->front)
	{
		pf(temp->dp);
		temp=temp->next;
	}
	pf(temp->dp);
}
bool queuedestroy(queue*q)
{
	if(q)
	{
		node*temp=q->front,*dlt;
		void*dout;
		while(temp->next!=q->front)
		{
			dlt=temp;
			temp=temp->next;
			dout=dlt->dp;
			free(dout);
			free(dlt);
		}
		free(q);
		return true;
	}
	
	return false;
}

	
	
