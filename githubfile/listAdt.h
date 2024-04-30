#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
	void*dp;
	struct node *next;
}node;
typedef struct list
{
	node*head;
    int count;
}list;
bool listempty(list*l)
{
	if(l->count!=0)
	{
		return false;
	}
	return true;
}
bool listfull()
{
	node*temp=(node*)malloc(sizeof(node));
	if(temp)
	{
		free(temp);
		return false;
	}
	return true;
}
 
list*creatlist()
{
	list*l=(list*)malloc(sizeof(list));
	if(l)
	{
		l->head=NULL;
		l->count=0;
		return l;
	}
	return NULL;
}
bool insertion(list*l,void*din,node*prev)
{
	node*newnode=(node*)malloc(sizeof(node));
	if(newnode)
	{
		newnode->dp=din;
		if(!prev)
		{
			newnode->next=l->head;
			l->head=newnode;
		}
		else
		{
			newnode->next=prev->next;
			prev->next=newnode;
		}
		l->count++;
		return true;
	}
	return false;
}
void*deletion(list*l,node*prev)
{
	void*dout;
	node*newnode;
	if(listempty(l))
	{
		return NULL;
	}
	if(!prev)
	{
		newnode=l->head;
		l->head=newnode->next;
	}
	else
	{
		newnode=prev->next;
		prev->next=newnode->next;
	}
	l->count--;
	dout=newnode->dp;
	free(newnode);
	return dout;
}
void listdisplay(list*l,void(*pf)(void*))
{
	node*temp=l->head;
	while(temp)
	{
		pf(temp->dp);
		temp=temp->next;
	}
}
bool listdestroy(list*p)
{
	if(p)
	{
	node*temp=p->head,*dlt;
	void*dp;
	while(temp!=NULL)
	{
		dlt=temp;
		temp=temp->next;	 
		dp=dlt->dp;
		free(dp);
		free(dlt);
	}
	free(p);
	return true;
  }
  return false;
}
node*serchlist(list*l,void*pkey,bool(*comp)(void*,void*))
{
	node*temp=l->head;
	while(temp)
	{
		if(comp(temp->dp,pkey))
		{
			return temp B VV
		}
		temp=temp->next;
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
		
