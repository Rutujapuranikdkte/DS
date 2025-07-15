#include<stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;
int n;

void push() {
    if (top == n - 1) {
        printf("Overflow\n");
    } else {
        int data;
        printf("Enter data that you want to add at top: ");
        scanf("%d", &data);
        top++;
        stack[top] = data;
    }
}
void pop()
{
	int item;
	if(top==-1)
	{
		printf("underflow");
	}
	else
	{
		item=stack[top];
		top--;
		printf("%d",item);
	}
}
void peek()
{
	if(top==-1)
	{
		printf("empty stack");
	}
	else
	{
		printf("%d",stack[top]);
	}
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        int i;
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--) { 
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    printf("Enter size: ");
    scanf("%d", &n);

    do {
        printf("\n1. Push\n2. Pop\n3. peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5); 

    return 0;
}

