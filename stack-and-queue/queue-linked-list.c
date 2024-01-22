#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insert();
void delet();
void display();

int main()
{
	printf("Welcome to DataFlair tutorials!\n\n");
	int choice;
	printf("LINKED LIST IMPLEMENTATION OF QUEUES\n\n");
	do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delet();
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
	while(choice != 4);
	return 0;
}
void insert()
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));       
	if (temp == NULL)
	{
		printf("Memory allocation error\n");
		exit(1);
	}
	printf("Enter the element to be inserted in the queue: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	if (rear == NULL)
	{
		front = rear = temp;
	}
	else
	{
		rear->link = temp;
		rear = temp;
	}
}

void delet()
{
	if (front == NULL)
	{
		printf("Queue underflow\n");
	}
	else
	{
		struct Node *temp = front;
		printf("The deleted element from the queue is: %d\n", front->data);
		front = front->link;
		free(temp);
	}
	// If the queue becomes empty, reset rear as well
	if (front == NULL)
	{
		rear = NULL;
	}
}
void display()
{
	struct Node *temp = front;
	if (temp == NULL)
	{
		printf("Queue underflow\n");
	}
	else
	{
		printf("The elements of the queue are:\n");
		while (temp)
		{
			printf("%d\n", temp->data);
			temp = temp->link;
		}
	}
}
