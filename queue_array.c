#include<stdio.h>
int front=0,rear = -1;
int n;
int queue[100]={1,2,3} 
void enqueue()
{
	int data;
	
	if(rear==n-1)
	{
		printf("overflow condition");
	}
	else
	{
		printf("enter data in the queue");
		scanf("%d",&data);
		rear++;
		queue[rear]=data;
	}
}
void dequeue()
{
	int item;
	if(front>rear)
	{
		printf("underflow condition");
	}
	else
	{
		item=queue[front];
		front++;
		printf("dequeued%d\n",item);
	}
}
void display()
{
	int i;
	if (rear < front)
    {
        printf("Queue is empty\n");
        return;
    }
	for(i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
}

int main()
{
	int num,i;
	printf("enter size of the queue:");
	scanf("%d",&n);
	printf("enter number of elements you want to insert");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
	enqueue();
	}
	for(i=0;i<num;i++)
	{
	dequeue();
	}
	display();
}
