#include<stdio.h>
#include<stdlib.h>
	void*(*pf)(void*,void*);
typedef struct comp
{
	int i,r;
}com;
int * intsum(void*n1,void*n2)
{
	int*sum=(int*)malloc(sizeof(int));
	*sum=*(int*)n1+*(int*)n2;
	return sum;
}
float* floatsum(void*n1,void*n2)
{
	float*sum=(float*)malloc(sizeof(float));
	*sum=*(float*)n1+*(float*)n2;
	return sum;
}
com *complex(void*n1,void*n2)
{
	com*s=(com*)malloc(sizeof(com));
	com*s1=(com*)n1;
	com*s2=(com*)n2;
	s->r=s1->r+s2->r;
	s->i=s1->i+s2->i;
	return s;
}
void*getfun(int ch)
{
	switch(ch)
	{
		case 1:return &intsum;
		case 2:return &floatsum;
		case 3:return &complex;
		default:NULL;
	}
	return NULL;
}
void* sumoftwo(void*n1,void*n2,void*(*pf)(void*,void*))
{
	return pf(n1,n2);
}
int main()
{
	int ch;
	void*(*pf)(void*,void*);
	void*n1,*n2;
	while(1)
	{
		printf(" ener the choice \n1-int sum\n2-floatsum\n3-compleaxsum\n4-exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:n1=(int*)malloc(sizeof(int));
			       n2=(int*)malloc(sizeof(int));
			       pf=getfun(ch);
			       printf(" enter the num1 and num2\n");
			       scanf("%d%d",(int*)n1,(int*)n2);
			       printf("sum of the %d and %d is %d \n",*(int*)n1,*(int*)n2,*(int*)sumoftwo(n1,n2,pf) );
			       break;
			case 2:n1=(float*)malloc(sizeof(float));
			       n2=(float*)malloc(sizeof(float));
			       pf=getfun(ch);
			       printf(" enter the num1 and num2\n");
			       scanf("%f%f",(float*)n1,(float*)n2);
			       printf("sum of the %f and %f is %f \n",*(float*)n1,*(float*)n2,*(float*)sumoftwo(n1,n2,pf) );
			       break;
			case 3:n1=(com*)malloc(sizeof(com));
			       n2=(com*)malloc(sizeof(com));
			       pf=getfun(ch);
			       printf(" enter the real num1 and num2\n");
			       scanf("%d%d",&((com*)n1)->r,&((com*)n2)->r);
			        printf(" enter the commpleax num1 and num2\n");
			       scanf("%d%d",&((com*)n1)->i,&((com*)n2)->i);
			       printf("sum of the compleax number if \n");
			       com*s=(com*)sumoftwo(n1,n2,pf);
			       printf("%d",s->r);
			       printf("%d",s->i);
			       break;
		   case 4:return 0;
		   default:printf("invalid choice\n");
	   }
   }
   return 0;
}
			       
		

