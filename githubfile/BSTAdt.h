#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"queuearr.h"
typedef struct Bnode
{
	void *dp;
	struct Bnode*left,*rigth;
}Bnode;
typedef struct Btree
{
	Bnode *root;
	int count;
	int(*com)(void*,void*);
	void(*printd)(void*);
}Btree;
Btree*creatbst(int(*com)(void*,void*),void(*printd)(void*))
{
	Btree*t=(Btree*)malloc(sizeof(Btree));
	if(t)
	{
		t->com=com;
		t->count=0;
		t->printd=printd;
		t->root=NULL;
		return t;
	}
	return NULL;
}
bool insertbst(Btree*t,void*din)
{
	Bnode*newnode=(Bnode*)malloc(sizeof(Bnode));
	if(newnode)
	{
		newnode->dp=din;
		newnode->left=newnode->rigth=NULL;
		if(!t->root)
		{
			t->root=newnode;
			return true;
		}
		Bnode*temp=t->root;
		Bnode*p=NULL;
		int x=0;
		while(temp)
		{
			p=temp;
			x=t->com(temp->dp,din);
			if(x==1)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->rigth;
			}
		}
		if(x==1)
		{
			p->left=newnode;
		}
		else
		{
			p->rigth=newnode;
		}
		t->count++;
		return true;
	}
	return false;
}
Bnode*small(Bnode*root)
{
	while(root->left)
		{
			root=root->left;
		}
		return root;
}
Bnode*large(Bnode*root)
{
		while(root->rigth)
		{
			root=root->rigth;
		}
		return root;
	 
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
void  breadtrav(Btree*t)
{
	queuearr*q=creatqueue();
	Bnode*curr=t->root;
	while(curr)
	{
		t->printd(curr->dp);
		if(curr->left)
		{
			Enqueue(q,curr->left);
		}
		if(curr->rigth)
		{
			Enqueue(q,curr->rigth);
		}
		if(!queueempty(q))
		{
			curr=(Bnode*)Dequeue(q);
		}
		else
		{
			curr=NULL;
		}
	}
}
void no_leafno(Bnode*root,int*leaf)
{
	if(root)
	{
		if(!root->left&&!root->rigth)
		{
			(*leaf)++;
		}
		if(root->left)
		{
			no_leafno(root->left,leaf);
		}
		if(root->rigth)
		{
			no_leafno(root->left,leaf);
		}
	}
}
int tree_h(Bnode*root)
{
	int hl,hr;
	if(root)
	{
		hl=tree_h(root->left);
		hr=tree_h(root->rigth);
		if(hl<hr)
		{
			return hr+1;
		}
		return hl+1;
	}
	return 0;
}
bool balence(Bnode*root)
{
	
	if(root)
	{
		int btre=tree_h(root->left)-tree_h(root->rigth);
		if(btre<1||btre>-1)
		{
			return false;
		}
		return true;
	}
	 return true;
}		
void key_parent(Btree*t,Bnode**parent,Bnode*root,void*pkey)
{
	if(root)
	{
		if(t->com(pkey,root->dp))
		{
			*parent=root;
			return;
		}
		if(root->left)
		{
			key_parent(t,parent,root->left,pkey);
			if(root->left==*parent&&t->com(root->left->dp,pkey))
			{
				*parent=root;
				return;
			}
		}
		if(root->rigth)
		{
			key_parent(t,parent,root->rigth,pkey);
			if(root->rigth==*parent&&t->com(root->rigth->dp,pkey))
			{
				*parent=root;
				return;
			}
		}
	}
}
void dlt(Bnode*root)
{
	if(root)
	{
		dlt(root->left);
		dlt(root->rigth);
		free(root->dp);
		free(root);
	}
}
		
bool tree_destroy(Btree*t)
{
	if(t)
	{
		Bnode*temp=t->root;
		dlt(temp);
		free(t->root);
		free(t);
		return true;
	}
	return false;
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
		bt->com=t->com;
		bt->count=t->count;
		bt->printd=t->printd;
		return bt;
	}
	return NULL;
}
Bnode* minValueNode(Bnode* root) {
    Bnode* current = root;

    // loop down to find the leftmost leaf
    while (current && current->left!= NULL)
        current = current->left;

    return current;
}
Bnode* deleteNode(Btree*t,Bnode* root, void* key) {
    // STEP 1: Perform standard BST delete
    if (root == NULL){
        return root;}
    int x=0;
    x=t->com(root->dp,key);
    if (x ==1){
        root->left = deleteNode(t,root->left, key);}
    else if (x==2)
        root->rigth = deleteNode(t,root->rigth, key);
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            Bnode* temp = root->rigth;
            free(root);
            return temp;
        } else if (root->rigth == NULL) {
            Bnode* temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder
        // successor (smallest in the right subtree)
        Bnode* temp = minValueNode(root->rigth);

        // Copy the inorder successor's data to this node
        root->dp = temp->dp;

        // Delete the inorder successor
        root->rigth = deleteNode(t,root->rigth, temp->dp);
    }
    return root;
}

	
