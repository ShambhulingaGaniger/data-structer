#include"queuearr.h"
void printdata(void*dp)
{
	printf("%s ",(char*)dp);
}
int main()
{
	char *pf;
	int ch;
	queuearr*q=creatqueue();
	if(!q)
	{
		printf("inavald choice\n");
		return 0;
	}
	while(1)
	{
		printf("enter the choice 1-e\n2-d\n3-rf\n4-rr\n5-qe\n6-qf\n7-qc\n8-disp\nexit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the float num\n");
			        pf=(char*)calloc(20,sizeof(char));
			        scanf("%s",pf);
			        if(Enqueue(q,pf))
			        {
						printf("succes\n");
					}
					else
					{
						printf("failed\n");
					}
					break;
			case 2:pf=(char *)Dequeue(q);
			       if(pf)
			       {
					   printf(" dequeue eliment is \n");
					   printdata(pf);
					   free(pf);
				   }
				   else
				   {
					   printf("failed\n");
					}
					break;
		   case 3:pf=(char *)retrive_front(q);
			       if(pf)
			       {
					   printf(" rerive front eliment is \n");
					   printdata(pf);
				   }
				   else
				   {
					   printf("failed\n");
					}
					break;
		 case 4:pf=(char *)retrive_rear(q);
			       if(pf)
			       {
					   printf(" rerive rear eliment is \n");
					   printdata(pf);
				   }
				   else
				   {
					   printf("failed\n");
					}
					break;
		case 5:if(queueempty(q))
			       {
					   printf(" queue is empty \n");
					   
				   }
				   else
				   {
					   printf("queue is not empty \n");
					}
					break;
		case 6:if(queuefull(q))
			       {
					   printf(" queue is full \n");
					   
				   }
				   else
				   {
					   printf("queue is not full \n");
					}
					break;
		case 7:printf("queue count is %d",queuecount(q));
		       break;
		case 8:printf("queue eliment are:");
		       queuedisplay(q,printdata);
		       break;
		case 9:if(queuedestroy(q))
		       {
				   printf(" destroy succse \n");
					   
				   }
				   else
				   {
					   printf("failed\n");
					}
					return 0;
		default:printf("invalid choice\n");
	 }
 }
 return 0;
}
		
						

