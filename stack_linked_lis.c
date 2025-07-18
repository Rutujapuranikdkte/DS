#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *top;
void push(int x)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->link=top;
	top=newnode;
}
void pop()
{
    struct node *tmp;
    tmp = top;
    if (top == NULL)
    {
        printf("empty stack\n");
    }
    else
    {
        printf("popped item is: %d\n", top->data);
        top = top->link;
        free(tmp);
    }
}

void peek()
{
	if(top==NULL)
	{
		printf("empty stack");
	}
	else
	{
		printf("%d",top->data);
	}
}
void display()
{
	struct node *tmp;
	tmp=top;
	if(top==NULL)
	{
		printf("empty stack");
	}
	else
	{
		while(tmp!=NULL)
		{
		printf("%d",tmp->data);
		tmp=tmp->link;
		}
		printf("\n");
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("1.push \n 2.pop \n 3.peek\n 4.display\n 5.exit");
		printf("enter choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
				
				int value;
				printf("enter value to push");
				scanf("%d",&value);
				push(value);
				break;
			}
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("wrong choice");
		}
	}
	
	return 0;
}
