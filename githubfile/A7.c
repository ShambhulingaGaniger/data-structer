#include"listAdt.h"
#include<string.h>
typedef struct cou
{
	char name[20],bra[20];
	int cie ,see;
}c;
void printdata(void*dp)
{
	c*x=(c*)dp;
	printf("studen name %s ",x->name);
	printf("student branch %s ",x->bra);
	printf("student cie markes %d ",x->cie);
	printf("sudent see markses %d ",x->see);
}
bool com(void*dp,void*dp1)
{
	c*x=(c*)dp;
	c*y=(c*)dp1;
	if(!strcmp(x->name,y->name))
	{
		return true;
	}
	return false;
}
int main()
{
	c*x;
	list*l=creatlist();
	int ch;
	char pkey[20];
	node*prev,*temp;
	if(!l)
	{
		printf("list creation failed \n");
		return 0;
	}
	while(1)
	{
		printf("\nenter the choice\n1-inserion\n2-deletion\n3-serch\n4-retrive\n5-listempty\n6-list full\n7-listdisplay\n8-exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:x=(c*)malloc(sizeof(c));
			        printf("enter the choice\n1)big\n2)mid\n3)last\n");
			         scanf("%d",&ch);
			         switch(ch)
			         {
						 case 1:prev=NULL;
						        break;
						 case 2:printf("ener the preves name to\n");
						        scanf("%s",pkey);
						        prev=serchlist(l,pkey,com);
						        break;
						 case 3:prev=l->head;
						        while(prev->next)
						        {
									prev=prev->next;
								}break;
						default:printf("invalid choice \n");
						 }
						 if(!prev&&ch==2)
						 {
							 printf("serch failed\n");
							 break;
						 }
						 printf("enter the name of the student\n");
						 scanf("%s",x->name);
						 printf("enter the branch  of the student\n");
						 scanf("%s",x->bra);
						 printf("enter the cie of the student\n");
						 scanf("%d",&x->cie);
						 printf("enter the see of the student\n");
						 scanf("%d",&x->see);
						 if(insertion(l,x,prev))
						 {
							 printf("inserton succes\n");
						 }
						 else
						 {
							  printf("inserton failsed\n");
						 }
						 break;
			case 2:printf("enter the deletion \n1-begine\n2-mid\n3-end\n");
			        scanf("%d",&ch);
			         switch(ch)
			         {
						 case 1:prev=NULL;
						        break;
						 case 2:printf("ener the preves name to\n");
						        scanf("%s",pkey);
						        prev=NULL;
						        temp=l->head;
						        while(temp&&strcmp(pkey,((c*)temp->dp)->name))
						        {
								   prev=temp;
								   prev=prev->next;
							     }
							     break;	
						 case 3:prev=NULL;
						       temp=l->head;
						        while(temp->next)
						        {
									prev=temp;
									prev=prev->next;
								}break;
						default:printf("invalid choice \n");
						 }
						 x=deletion(l,prev);
						 if(x)
						 {
							 printdata(x);
							 free(x);
						 }
						 else
						 {
							 printf("deltion failed\n");
						 }
						 break;
				case 4:printf("enter the pkey to retrive\n");
						       scanf("%s",pkey);
						       x=(c*)retrive(l,pkey,com);
						       printdata(x);
						       break;
						case 5:if(!listempty(l))
						       {
						       printf("list is not empty\n");
						       
						      }else
						      {
								  printf("list is empty\n");
							  }
							  break;
					   case 6:if(listempty(l))
					          {
								  printf("list is empty \n");
							  }
							  else
							  {
								  printf("list is empty \n");
							  }
							  break;
					  case 7:printf("list conatinets are :\n");
					         listdisplay(l,printdata);
					         break;
					  case 8:if(listdestroy(l))
					  {
						  printf("succes\n");
					  }
					  else
					  {
						  printf("failed\n");
					  }
					  break;
					  default:printf("in valid coice \n");
				   }
			   }
			   return 0;
		   }
						          
									 		
	
	
	
