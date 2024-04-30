#include"stackarr.h"
void printdata(void*dp)
{
	printf("%d ",*(int*)dp);
}
int main()
{
	int *x;
	int ch;
	arrstack*head;
	head=creatstack();
	if(!head)
	{
		printf("stack creation is failed\n");
		return 0;
	} 
	while(1)
	{
		printf("enter the choice\n1-for push\n2-for pop\n3-forstacktop\n4-stackempty\n5-for stackfull\n6-for stakdisplay\n7-for exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:x=(int*)malloc(sizeof(int));
			       printf("enter the number to push\n");
			       scanf("%d",x);
			       if(stackpush(head,x))
			       {
					   printf("push is succes\n");
				   }
				   else
				   {
					   printf("push is faile\n");
				   }
				   break;
			case 2:x=(int*)stackpop(head);
			       if(x)
			       {
					   printdata(x);
				   }
				   else
				   {
					   printf("failed\n");
				   }
				   break;
		   case 3:x=(int*)stacktop(head);
		           if(x)
		          {
					  printdata(x);
				  }
				  else
				  {
					  printf("failed\n");
				  }
				  break;
		   case 4:if(stackempty(head))
		          {
					  printf("stack is empty\n");
				  }
				  else
				  {
					  printf("stack is not empty\n");
				  }
				  break;
		 case 5:if(stackfull(head))
		          {
					  printf("stack is full\n");
				  }
				  else
				  {
					  printf("stack is not full\n");
				  }
				  break;
		 case 6:printf("stack containce are\n");
		          stackdisplay(head,printdata);
		        break;
		 case 7:if(stackdestroy(head))
		          {
					  printf("stack destroy succ\n");
				  }
				  else
				  {
					  printf("stack is destroy failed\n");
				  }
				  return 0;
				  break;
				  default:printf("invalid choice\n");
			  }
		  }return 0;
	  }
		        
				  

