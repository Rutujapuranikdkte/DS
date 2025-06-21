#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node *next;
};

// Global head pointer
struct node *head = NULL;

// Function to create a linked list
void create() {
    struct node *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Continue? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    }
}

// Function to insert at beginning
void insertbeg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data to insert at beginning: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// Function to insert at end
void insertend() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data to insert at end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to delete from beginning
void deletebeg() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        temp = head;
        head = head->next;
        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}

// Function to display the linked list
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create node(s)\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Delete from beginning\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insertbeg();
                break;
            case 3:
                insertend();
                break;
            case 4:
                deletebeg();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

