#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"queuell.h"
typedef struct Bnode
{
	void*dp;
	struct Bnode*left,*rigth;
}Bnode;
typedef struct Broot
{
	Bnode*root;
	int count;
	bool (*com)(void*,void*);
	void(*printd)(void*);
}Btree;
Btree*creattree(bool (*com)(void*,void*),void(*printd)(void*))
{
	Btree*t=(Btree*)malloc(sizeof(Btree));
	if(t)
	{
		t->root=NULL;
		t->count=0;
		t->com=com;
		t->printd=printd;
		return t;
	}
	return NULL;
}
bool insertion_tree(Btree*t,void*din)
{
	Bnode*newnode=(Bnode*)malloc(sizeof(Bnode));
	if(newnode)
	{
		Bnode*traversal=t->root,*par=NULL;
		int ch;
		while(traversal)
		{
			printf("enter the choice \n1-left\n2-right\n");
			scanf("%d",&ch);
			par=traversal;
			if(ch==1)
			{
				traversal=traversal->left;
			}
			else if(ch==2)
			{
				traversal=traversal->rigth;
			}
			else
			{
				printf("invalis choice\n");
			}
		}
		newnode->dp=din;
		newnode->left=newnode->rigth=NULL;
		if(!t->root)
		{
			t->root=newnode;
		}
		else if(ch==1)
		{
			par->left=newnode;
		}
		else
		{
			par->rigth=newnode;
		}
		return true;
	}
	return false;
}
bool  find_key(Btree*t,Bnode*root,void*pkey)
{
	if(root)
	{
		if(t->com(root->dp,pkey))
		{
			return true;
		}
		if(root->left)
		{
		  return find_key(t,root->left,pkey);
	    }
	    if(root->rigth)
	    {
			return find_key(t,root->rigth,pkey);
	    }
	}
	return false;
}
void  find_keyfrq(Btree*t,Bnode*root,void*pkey,int*frq)
{
	if(root)
	{
		if(t->com(root->dp,pkey))
		{
			(*frq)++;
		}
		if(root->left)
		{
		 find_keyfrq(t,root->left,pkey,frq);

	    if(root->rigth)
	    {
			 find_keyfrq(t,root->rigth,pkey,frq);
	    }
	}
}
void preorder_traversal(Btree*t,Bnode*root)
{
	if(root)
	{
		t->printd(root->dp);
		if(root->left)
		{
			preorder_traversal(t,root->left);
		}
		if(root->rigth)
		{
			preorder_traversal(t,root->rigth);
		}
	}
}
void inorder_traversal(Btree*t,Bnode*root)
{
	if(root)
	{
		
		if(root->left)
		{
			inorder_traversal(t,root->left);
		}
		t->printd(root->dp);
		if(root->rigth)
		{
			inorder_traversal(t,root->rigth);
		}
	}
}
void postorder_traversal(Btree*t,Bnode*root)
{
	if(root)
	{
		
		if(root->left)
		{
			postorder_traversal(t,root->left);
		}
		if(root->rigth)
		{
			postorder_traversal(t,root->rigth);
		}
		t->printd(root->dp);
	}
}
		
	  
		
			
			
