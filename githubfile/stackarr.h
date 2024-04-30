#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct arr
{
	void**st;
	int top,count,size;
}arrstack;
bool stackempty(arrstack*head)
{
	if(head->count==0)
	{
		return true;
	}
	return false;
}
bool stackfull(arrstack*head)
{
	if(head->count==head->size)
	{
		return true;
	}
	return false;
}
arrstack*creatstack()
{
	arrstack*head=(arrstack*)malloc(sizeof(arrstack));
	if(head)
	{  
	  printf("enter the size \n");
	  scanf("%d",&head->size);
	  head->st=(void**)calloc(head->size,sizeof(void*));
	  if(head->st)
	  {
		  head->top=-1;
		  head->count=0;
		  return head;
	  }
  }
  return NULL;
}
bool stackpush(arrstack*head,void*din)
{
	if(stackfull(head))
	{
		return false;
	}
	head->top++;
	head->st[head->top]=din;
	head->count++;
	return true;
}
void* stackpop(arrstack*head)
{
	if(stackempty(head))
	{
		return NULL;
	}
	void*dout;
	dout=head->st[head->top];
	head->top--;
	head->count--;
	return dout;
}
void* stacktop(arrstack*head)
{
	if(stackempty(head))
	{
		return NULL;
	}
	return head->st[head->top];
}
int stackcount(arrstack*head)
{
	return head->count;
}
void stackdisplay(arrstack*head,void(*pf)(void*))
{
	int temp=0;
	for(temp=head->top;temp>=0;temp--)
	{
		pf(head->st[temp]);
	}
}
bool stackdestroy(arrstack*head)
{
	if(head){
	void*dp;
	for(int i=head->top;i>=0;i--)
	{
		dp=head->st[i];
		free(dp);
	}
	free(head->st);
	free(head);
	return false;
}
return true;
}


  
	
