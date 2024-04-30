
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
	void*dp;
	struct node *next;
}node;
typedef struct List
{
	node *head;
	int count;
}list;
list*creatlist()
{
	list*p=(list*)malloc(sizeof(list));
	if(p)
	{
		p->count=0;
		p->head=NULL;
		return p;
	} 
	return NULL;
}
node*serchlist(list*p,void*dp,bool(*com)(void*,void*))
{
	if(p->count==0)
	{
		return NULL;
	}
	node*temp;
	temp=p->head;
	while(temp->next!=p->head)
	{
		if(com(temp->dp,dp))
		{
			return temp;
		}
		temp=temp->next;
	}
	  if(com(temp->dp,dp))
		{
			return temp;
		}
	return NULL;
}
void*retrive(list*p,void*dp,bool(*com)(void*,void*))
{
	node*temp=serchlist(p,dp,com);
	if(temp)
	{
		return temp->dp;
	}
	return NULL;
}
bool listfull()
{
	node*temp=(node*)malloc(sizeof(node));
	if(temp)
	{
		return false;
	}
	return true;
}
bool listempty(list*p)
{
	
	if(!p->count==0)
	{
		return false;
	}
	return true;
}
int listcount(list*p)
{
	return p->count;
}
void listdisplay(list*p,void(*pf)(void*))
{
	node*temp=p->head;
	while(temp->next!=p->head)
	{
		pf(temp->dp);
		temp=temp->next;
	}
	pf(temp->dp);
}
bool listdestroy(list*p)
{
	if(p)
	{
	node*temp=p->head,*dlt;
	void*dp;
	while(temp->next!=p->head)
	{
		dlt=temp;
		temp=temp->next;	 
		dp=dlt->dp;
		free(dp);
		free(dlt);
	}
	free(temp->dp);
	free(temp);
	free(p);
	return true;
  }
  return false;
}
bool circular_i(list*p,node*prev,void*din)
{
	node*newnode=(node*)malloc(sizeof(node));
	newnode->dp=din;
	if(listempty(p))
	{
		p->head=newnode;
		newnode->next=newnode;
		p->count++;
		return true;
	}
	if(!prev)
	{
		node*temp=p->head;
		while(temp->next!=p->head)
		{
			temp=temp->next;
		}
		newnode->next=p->head;
		p->head=newnode;
		temp->next=p->head;
		p->count++;
	}
	else
	{
		newnode->next=prev->next;
		prev->next=newnode;
		p->count++;
	}
	return true;
}
void*circular_d(list*p,node*prev)
{
	node*temp=p->head,*temp2;
	if(listempty(p))
	{
		return NULL;
	}
	if(!prev)
	{
		temp=temp2=p->head;
		while(temp2->next!=p->head)
		    temp2=temp2->next;
		p->head=temp->next;    
		temp2->next=p->head;
	}
	else
	{
		temp=prev->next;
		prev->next=temp->next;
	}
	void*dout=temp->dp;
	p->count--;
	return dout;
}
void circular_di(list*p,void(*pf)(void*))
{
	node*temp=p->head;
	while(temp->next!=p->head)
	{ 
		pf(temp->dp);
		temp=temp->next;
	}
	pf(temp->dp);
}

