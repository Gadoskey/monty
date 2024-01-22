#include <stdio.h>
#include <stdlib.h>
#define LIMIT 10

/* Global declaration of variables */
int cqueue[LIMIT];
int front = -1, rear = -1; // It indicates the queue is empty
int choice, item;

void insert();
void delet();
void display();

int main() {
	    printf("Welcome to DataFlair tutorials!\n\n");
	        printf("ARRAY IMPLEMENTATION OF QUEUES\n\n");

		    do {
			            printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
				            printf("Enter your choice: ");
					            scanf("%d", &choice);

						            switch (choice) {
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
							        } while (choice != 4);

		        return 0;
}

void insert() {
	    if ((front == 0 && rear == LIMIT - 1) || (front == rear + 1)) {
		            printf("Queue Overflow\n");
			            return;
				        }

	        printf("Enter the element to be inserted in the queue: ");
		    scanf("%d", &item);

		        if (front == -1) { // If the queue is empty
				        front = rear = 0;
					    } else {
						            if (rear == LIMIT - 1) { // When rear is at the last position of the queue
								                rear = 0;
										        } else {
												            rear++;
													            }
							        }

			    cqueue[rear] = item;
}

void delet() {
	    if (front == -1) {
		            printf("Queue Underflow\n");
			            return;
				        }

	        printf("Element deleted from the queue is: %d\n", cqueue[front]);

		    if (front == rear) { /* queue has only one element */
			            front = rear = -1;
				        } else {
						        if (front == LIMIT - 1) {
								            front = 0;
									            } else {
											                front++;
													        }
							    }
}

void display() {
	    int front_position = front;
	        int rear_position = rear;

		    if (front == -1) {
			            printf("Queue underflow\n");
				            return;
					        }

		        printf("The elements of the queue are:\n");

			    if (front_position <= rear_position) {
				            while (front_position <= rear_position) {
						                printf("%d\n", cqueue[front_position]);
								            front_position++;
									            }
					        } else {
							        while (front_position <= LIMIT - 1) {
									            printf("%d\n", cqueue[front_position]);
										                front_position++;
												        }

								        front_position = 0;

									        while (front_position <= rear_position) {
											            printf("%d\n", cqueue[front_position]);
												                front_position++;
														        }
										    }
}

