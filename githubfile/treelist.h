#include"QUEUELLADT.h"
typedef struct Node
{
	void*dp;
	struct Node *left,*rigth;
}Bnode;
typedef struct tree
{
	Bnode*root;
	int count;
	bool (*comp)(void*,void*);
	void (*pf)(void*);
}Btree;
Btree*creattree(bool (*comp)(void*,void*),void (*pf)(void*))
{
	Btree*t=(Btree*)malloc(sizeof(Btree));
	if(!t)
	{
		return NULL;
	}
	t->comp=comp;
	t->count=0;
	t->pf=pf;
	t->root=NULL;
	return t;
}
bool insertion_tree(Btree*t,void*dp)
{
	Bnode*newnode=(Bnode*)malloc(sizeof(Bnode));
	if(!newnode)
	{
	  return false;
    }
	newnode->dp=dp;
	newnode->left=newnode->rigth=NULL;
	Bnode*traves=t->root,*parent=NULL;
	int ch;
	while(traves)
	{
	   printf("enter the choice\n1)left\n2)rigth\n");
	   scanf("%d",&ch);
	   parent=traves;
	   if(ch==1)
	   {
		   traves=traves->left;
	   }
	   else if(ch==2)
	   {
		   traves=traves->rigth;
	   }
	   else
	   {
		   printf("invalid choiice \n");
	   }
	   
    }
	   if(!t->root)
	   {
		   t->root=newnode;
	   }
		else if(ch==1)
		{
		  parent->left=newnode;
	    }
		else if(ch==2)
		{
		  parent->rigth=newnode;
	    }
		 t->count++;
		 return true;
}
bool find_key(Btree*t,Bnode*root,void*key)
{
	if(root)
	{
		if(t->comp(root->dp,key))
		{
			return true;
		}
		if(root->left)
		{
			if(find_key(t,root->left,key))
			{
				return true;
			}
		}
		if(root->rigth)
		{
			if(find_key(t,root->rigth,key))
			{
				return false;
			}
		}
	}
	return false;
}
void find_key_fre(Btree*t,Bnode*root,void*key,int*fre)
{
	if(root)
	{
		if(t->comp(root->dp,key))
		{
			(*
			fre)++;
		}
		if(root->left)
		{
			find_key_fre(t,root->left,key,fre);
		}
		if(root->rigth)
		{
			find_key_fre(t,root->rigth,key,fre);
		}
	}
}
void preorder_traversal(Btree*t,Bnode*root)
{
	if(root)
	{
		t->pf(root->dp);
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
		t->pf(root->dp);
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
		t->pf(root->dp);
	}
}
void no_of_leaf(Bnode*root,int*leaf)
{
	if(root)
	{
		if(!root->left&&!root->rigth)
		{
			(*leaf)++;
		}
		if(root->left)
		{
			no_of_leaf(root->left,leaf);
		}
		if(root->rigth)
		{
			no_of_leaf(root->rigth,leaf);
		}
	}
}
int t_height(Bnode*root)
{
	int hl,hr;
	if(root)
	{
			hl=t_height(root->left);
			hr=t_height(root->rigth);
		if(hl<hr)
		{
			return hr+1;
		}
		return hl+1;
	}
	return 0;
}
bool  t_balence(Bnode*root)
{
	int hl,hr,bra;
	if(root)
	{
			hl=t_balence(root->left);
			hr=t_balence(root->rigth);
			bra=hl-hr;
		if(bra<=1&&bra>=-1)
		{
			return true;
		}
		return false;
	}
	 return true;
}
void dlt_node(Bnode*root)
 {
	 if(root)
	 {
		 dlt_node(root->left);
		 dlt_node(root->rigth);
		 free(root->dp);
		 free(root);
	 }
}
bool destroy(Btree*t)
{
	if(t)
	{
		Bnode*temp=t->root;
		dlt_node(temp);
		free(t);
		return true;
	}
	return false;
}
 
void Breathth(Btree*t)
{
	Bnode*curr;
	queue*q=creatqueue();
	curr=t->root;
	while(curr)
	{
		t->pf(curr->dp);
		if(curr->left)
		{
			if(Enqueu(q,curr->left));
		}
		if(curr->rigth)
		{
			if(Enqueu(q,curr->rigth));
		}
		if(!qempty(q))
		{
			curr=(Bnode*)dequeue(q);
		}
		else
		{
			curr=NULL;
		}
	}
}
Bnode*creatnewtree(Bnode*root)
{
	Bnode*newnode=(Bnode*)malloc(sizeof(Bnode));
	if(newnode)
	{
		if(root)
		{
			newnode->dp=root->dp;
			newnode->left=creatnewtree(root->left);
			newnode->left=creatnewtree(root->rigth);
			return newnode;
		}
		
	}
	return NULL;
}
Btree*copy_btree(Btree*t)
{
	Btree*bt=(Btree*)malloc(sizeof(Btree));
	if(bt)
	{
		bt->root=creatnewtree(t->root);
		bt->comp=t->comp;
		bt->count=t->count;
		bt->pf=t->pf;
		return bt;
	}
	return NULL;
}

		 
	  


				

		     
	   
	   
