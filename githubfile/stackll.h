#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
	void*dp;
	struct node *next;
}Node;
typedef struct stack
{
	Node*top;
	int count;
	void(*printd)(void*);
}stack;
stack*creatstack(void(*printd)(void*))
{
	stack*head=(stack*)malloc(sizeof(stack));
	if(head)
	{
		head->count=0;
		head->top=NULL;
		head->printd=printd;
		return head;
	}
	return NULL;
}
bool stackpush(stack*head,void*din)
{
	Node*newnode=(Node*)malloc(sizeof(Node));
	if(newnode)
	{
		newnode->dp=din;
		newnode->next=head->top;
		head->top=newnode;
		head->count++;
		return true;
	}
	return false;
}
void*stackpop(stack*head)
{
	Node*curr=head->top;
	void*dout;
	if(head->count==0)
	{
		return NULL;
	}
	dout=curr->dp;
	head->top=curr->next;
	head->count--;
	free(curr);
	return dout;
}
void*stacktop(stack*head)
{
	if(head->count==0)
	{
		return NULL;
	}
	return head->top->dp;
}
bool stackempty(stack*head)
{
	if(head->count==0)
	{
		return true;
	}
	return false;
}
bool stackfull()
{
	Node*temp=(Node*)malloc(sizeof(Node));
	if(temp)
	{
		free(temp);
		return false;
	}
	return true;
}
int stackcount(stack*head)
{
	return head->count;
}
void stackdisplay(stack*head)
{
	Node*temp=head->top;
	while(temp)
	{
		head->printd(temp->dp);
		temp=temp->next;
	}
}
bool stackdestroy(stack*head)
{
	if(head)
	{
		Node*temp=head->top,*dlt;
		void*dout;
	while(temp)
	{
		dlt=temp;
		temp=temp->next;
		dout=dlt->dp;
		free(dout);
		free(dlt);
	}
	free(head);
	return true;
  }
  return false;
}

	
	
	
