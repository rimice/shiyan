#include<stdio.h>
#include<time.h>
#define N 1000
#define M 20


/*
*the node
*/
struct node 
{
	int number;
	struct node *next;
};
struct node *nodep,*head;



/*****************************************************************************************
***	Description:		
***		 Creat node 
***	
***	Return Value:
***		Return head pointer.
*******************************************************************************************/
struct node* creat(struct node* head)
{
	struct node *newp;
	newp = (struct node*)malloc(sizeof(struct node*));
	if(newp ==NULL)
	{
		printf("malloc is error\n");
		return NULL;
	}
	
	if( head==NULL )
	{
		head=newp;
		head->next=NULL;
	}
	else
	{
		printf("error,node is exit,please insert\n");
		return head;
	}
	printf("creat a node is ok\n");
	return head;
}



/*****************************************************************************************
***	Description:		
***		 Insert node 
***	
***	Return Value:
***		Return head pointer.
*******************************************************************************************/
struct node* insert(struct node* head)
{	
	int *number=(int *)malloc(M*sizeof(int))
	srand(time(NULL));
	struct node *temp,*newp,*p;
	p=head;
	if(p==NULL)
	{
		printf("please creat a node first\n");
		return NULL ;
	}

	newp = (struct node*)malloc(sizeof(struct node));
	if(newp==NULL)
	{
		printf("malloc is error\n");
	}
	
	number[0]=rand();
	for(j=1;j<M;j++)
	{
		//check and gererate
		temp=rand();
		for(i=0;i<j & temp==number[i];i++)
		{	
			if (temp == number[i])
			printf("date=%d is the same,reselect\n",number[j]);
			else
			temp=rand();	
		}	
		number[j]=temp;
	}
	

	while((p->num<newp->num)&&(p->next!=NULL))
	{
		temp=p;
		p=p->next;
	}

	if(p->num < newp->num)
	{		
		p->next=newp;
		newp->next=NULL;
		
	}
	else
	{	
		if(p==head)
		{
			newp->next=p;	
			head=newp;				
		}
		else
		{
			temp->next=newp;
			newp->next=p;
		}
	}
	printf("insert a node is ok\n");
	return head;
  
}




/*****************************************************************************************
***	Description:		
***		 Display node 
***	
***	Return Value:
***		Void
*******************************************************************************************/
void show(struct node* head)
{
	struct node* temp;
	temp=head;
	if(temp==NULL)
	{
		printf("please creat a node first\n");
		return;
	}
	else
	{
		while(temp !=NULL)
		{
			printf("num:%d  name:%s  sex:%s  age:%d  \n",temp->num,temp->name,temp->sex,temp->age);
			temp=temp->next;
		}
	}
}

