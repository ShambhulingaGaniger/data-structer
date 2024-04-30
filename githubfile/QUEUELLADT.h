#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct NODE
{
    void *dp;
    struct NODE*next;
}node;
typedef struct QUEUE
{
    node *front,*rear;
    int count;
}queue;
bool qempty(queue*q)
{
    if(q->count==0)
    {
        return true;
    }
    return false;
}

bool qfull()
{
    node *temp=(node*)malloc(sizeof(node));
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
bool Enqueu(queue*q,void *dp)
{
    node *temp=(node*)malloc(sizeof(node));
    if(qfull())
    {
        return false;
    }
    if(!temp)
    {
        return false;
    }
    temp->dp=dp;
    temp->next=NULL;
    if(qempty(q))
    {
        q->front=temp;
    }
    else{
       q->rear->next=temp;
    } 
    q->rear=temp;
    q->count++;
    return true;
}
void* dequeue(queue*q)
{
    node*temp;
    void *dp;
    if(qempty(q))
    {
       return NULL;
    }
    temp=q->front;

    if(q->count==1)
    {
        q->rear=NULL;
    }
    q->front=temp->next;
    q->count--;
    dp=temp->dp;
    free(temp);
    return dp;
}
void *Retrival_front(queue*q)
{
    if(qempty(q))
    {
        return NULL;
    }
    return q->front->dp;
}
void *Retrival_rear(queue*q)
{
    if(qempty(q))
    {
        return NULL;
    }
    return q->rear->dp;
}
int qcount(queue*q)
{
    return q->count;
}

void qdisplay(queue *q,void(*printdata)(void*))
{
    node*temp;
    for(temp=q->front;temp!=NULL;temp=temp->next)
    {
        printdata(temp->dp);
    }
}
void qdestroy(queue*q)
{
     node*temp,*dlt;
     void*dp;
     if(!q)
     {
        return ;
     }
    for(temp=q->front;temp!=NULL;temp=temp->next)
    {
      dlt=temp;
        temp=temp->next;
        dp=dlt->dp;
        free(dp);
        free(dlt);
    }
    free(q);
    
} 

