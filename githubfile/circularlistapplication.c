#include"A8.h"
bool compare(void*d1,void*d2)
{
	if(*(int*)d1==*(int*)d2)
	{
		return true;
	}
	return false;
}
void printdata(void*dp)
{
	printf("%d  ",*(int*)dp);
}
int main()
{
	Btree*t,*bt;
	Bnode*p;
	int *din,ch,frq=0,leaf=0;
	t=creattree(compare,printdata);
	if(!t)
	{
		return 0;
	}
	while(1)
	{
		printf(" enter the choice \n1-inseron \n2-serch\n3-key frequency \n4-no of leaf node\n5-tree traversal \n6-balance\n7-parent key\n8-copy\n9-exit\n");
		scanf("%d",&ch);
		din=(int*)malloc(sizeof(int));
		switch(ch)
		{
			case 1: printf("enter the number\n");
			scanf("%d",din);
			if(insertion_tree(t,din))
			{
				printf("succ\n");
			}
			else
			{
				printf("not \n");
			}
			break;
	      case 2:printf("enter the key to serch\n");
	      scanf("%d",din);
	      if(find_key(t,t->root,din))
	      {
			  printf("find \n");
			}
			else
			{
				printf("not find  \n");
			}
			break;
		case 3:printf("enter the frequency number\n");
		       scanf("%d",din);
		       find_keyfrq(t,t->root,din,&frq);
		       printf("number of frequncy %d is %d\n",*din,frq);
		       break;
		case 4:
		       no_leafno(t->root  ,&leaf);
		        printf("number of leaf node %d",leaf);
			    break;
	    case 5:printf(" enter the choice\n 1-preorder\n 2- inorder \n3-posorder\n4-bredth\n"); 
	           scanf("%d",&ch);
	           switch(ch)
	           {
				   case 1:printf("preordr\n");
				     preorder_traversal(t,t->root);
				          break;
				   case 2:printf("inordr\n");
				      inorder_traversal(t,t->root);
				     break;
				   case 3:printf("postordr\n");
				   postorder_traversal(t,t->root);
				   case 4:Breathth(t);
				     break;
				     default:printf("invalid choice \n");
				}
				break;
		case 6:if(balence(t->root))
		{
			printf("balence\n");
		}
		else
		{
			printf("no balance\n");
		}
		break;
	    case 8: bt=copy_btree(t);
	           if(bt)
	         {
				 printf("succes\n");
				 inorder_traversal(bt,bt->root);
			 }
			 else
			 {
				 printf("fuck\n");
			 }
			 break;
		case 7:din=(int*)malloc(sizeof(int));
		       printf("ener the number parent to be find\n");
		       scanf("%d",din);
		       key_parent(t,&p,t->root,din);
		       if(p)
		       {
				   printf("parent eimment is %d",*(int*)p->dp);
				   
			   }
			   else
			   {
				   printf("failed\n");
			   }
			   break;
			 default:printf("invalid choice\n");
			 
	}
	
}
return 0;
}
	      
