#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
        struct Node* next;
};

struct Node* top = NULL;

void push();
void pop();
void display();

int main()
{
	int choice;
	printf("Welcome to DataFlair tutorials!\n\n");
	do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Sorry, invalid choice!\n");
				break;
		}
	}
	while (choice != 4);
	return 0;
}
void push()
{
	int data;
	printf("Enter the element to be inserted: ");
	scanf("%d", &data);
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		printf("Memory allocation error (Stack overflow)\n");
		return;
	}
	newNode->data = data;
	newNode->next = top;
	top = newNode;
}
void pop()
{
	if (top == NULL)
	{
		printf("Stack Underflow\n");
		return;
	}
	struct Node* temp = top;
	int item = temp->data;
	top = temp->next;
	free(temp);
	printf("The deleted item is %d\n", item);
}
void display()
{
	if (top == NULL)
	{
		printf("Stack underflow\n");
		return;
	}
	struct Node* current = top;
	printf("The elements of the stack are:\n");
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}
